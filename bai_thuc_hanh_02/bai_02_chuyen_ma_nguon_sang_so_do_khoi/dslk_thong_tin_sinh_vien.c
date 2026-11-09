#include<stdio.h>
#include<stdlib.h>
typedef struct    {
    	char hoten[30];
    	int masv;
    	float d1, d2, d3;
}Data;
typedef struct tagNode    {
    	Data infor;
    	struct tagNode *link;
}Node;
typedef struct    {
    	Node *pHead;  
    	Node *pTail;
    	int spt;
}LList;

void initList(LList *L)
    {
    	L->pHead = NULL;
    	L->pTail = NULL;
    	L->spt = 0;
    }

int emptyList(LList L)
 {
    	return (L.spt == 0); 
}

void insert_Head(LList *L, Data x)
    {
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->link = NULL;
    	if(emptyList(*L)){
    			L->pHead = pp;
    			L->pTail = pp;
    		}  	
        else {
    		pp->link = L->pHead;
    		L->pHead = pp;
    		}
    	L->spt++;
    }

void insert_Tail(LList *L, Data x)
    {
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->link = NULL;
    	if(emptyList(*L)){
    			L->pHead = pp;
    			L->pTail = pp;
    		}
        else {
    		L->pTail->link = pp;
    		L->pTail = pp;
    		}
    	L->spt++;
    }

Node* timKiem(LList L, int ma){
    Node *pp = L.pHead;
    while( pp != NULL && pp->infor.masv != ma ){
        pp = pp->link;
    }
    return pp;
}

void insert_After(LList *L, Node *q, Data x)
    {
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->link = q->link;
    	q->link = pp;
    	if(q == L->pTail){
    		L->pTail = pp;
    	}
    	L->spt++;
    }

void delete_Head(LList *L)
    {
    	Node *pp;
    	if(emptyList(*L)){
    		printf("Danh sach rong\n");
    		return;
    	}
    	pp = L->pHead;
    	L->pHead = pp->link;
    	if(L->pHead == NULL){
    		L->pTail = NULL;
    	}
    	free(pp);
    	L->spt--;
    }

void delete_Ma(LList *L, int ma)
    {
    	Node *pp = L->pHead;
    	Node *truoc = NULL;
    	while( pp != NULL && pp->infor.masv != ma ){
    		truoc = pp;
    		pp = pp->link;
    	}
    	if(pp == NULL){
    		printf("Khong tim thay sinh vien co ma %d\n", ma);
    		return;
    	}
    	if(truoc == NULL){
    		L->pHead = pp->link;
    	}
    	else {
    		truoc->link = pp->link;
    	}
    	if(pp == L->pTail){
    		L->pTail = truoc;
    	}
    	free(pp);
    	L->spt--;
    	printf("Da xoa\n");
    }

void nhap(Data *x){
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));
    if(x->masv > 0){
        printf("Nhap ho ten: ");
        scanf(" %29[^\n]", (x->hoten));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}
void in(Data x){
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 3: %.2f\n", 
            x.hoten, x.masv, x.d1, x.d2, x.d3);
}
void processList(LList L){
    Node *pp = L.pHead;
    if(emptyList(L)){
        printf("Danh sach rong\n");
    }
    while( pp != NULL ){
        	in(pp->infor);
        	pp = pp->link;
    	}
}

int main(){
    LList L;
	int kt = 0;
	Data x;
	initList(&L);
	do{
	    printf("\nChuong trinh lam viec voi DSLK don SV\n");
	    printf("\n1: Them nut vao dau danh sach");
	    printf("\n2: Them nut vao cuoi danh sach");
	    printf("\n3: Them nut vao sau mot nut khac trong danh sach");
	    printf("\n4: Xoa nut dau danh sach");
	    printf("\n5: Xoa nut theo ma sinh vien");
	    printf("\n6: Tim kiem sinh vien");
	    printf("\n9: Duyet ds");
	    printf("\n0: Thoat");
	    printf("\nMoi ban chon: ");
	    int chon, ma;
	    Node *q;
	    scanf("%d", &chon);
	    switch(chon){
	        case 1: 
	            printf("Nhap thong tin sv can them\n");
	            nhap(&x);
	            if(x.masv > 0) 
                	insert_Head(&L, x);
            	break;
            case 2:	
	            printf("Nhap thong tin sv can them\n");
	            nhap(&x);
	            if(x.masv > 0) 
                	insert_Tail(&L, x);
            	break;
            case 3:
	            printf("Nhap ma sv de them vao sau: ");
	            scanf("%d", &ma);
	            q = timKiem(L, ma);
	            if(q == NULL){
	                printf("Khong tim thay sinh vien co ma %d\n", ma);
	            }
	            else {
	                nhap(&x);
	                if(x.masv > 0)
	                    insert_After(&L, q, x);
	            }
            	break;
            case 4: 
                delete_Head(&L);
                break;
            case 5:
                printf("Nhap ma sv can xoa: ");
                scanf("%d", &ma);
                delete_Ma(&L, ma);
                break;
            case 6:
                printf("Nhap ma sv can tim: ");
                scanf("%d", &ma);
                q = timKiem(L, ma);
                if(q == NULL)
                    printf("Khong tim thay\n");
                else
                    in(q->infor);
                break;
            case 9: 
                processList(L);
                break;    
            case 0: 
                printf("Bye bye\n");
	            kt = 1;
        }
	}while(kt==0); 
}
