#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#define true 1
#define false 0
typedef struct _List{
       struct  _List *next;
       int val;
}List;

List  *GetKeyNode(const List *head,unsigned int val){
    List *curr = head;
    while(curr != NULL){
        if( curr->val == val){
            //printf("get \n");
            return curr;
        }
        curr = curr->next;
    }
    printf("NULL \n");
    return NULL;
}

List *LinkListCreate(const unsigned int  InputVal){
        List  *temp = malloc(sizeof(List));
        temp->val = InputVal;
        temp->next = NULL;
        return temp;  
}
void insert_node(List* n1, List* n2) // 將 n2 插入在 n1 之後
{
    n2->next = n1->next;
    n1->next = n2;
}


void swap_list(List **head, List *a, List *b) {
        List *prev_A =NULL,*prev_B =NULL;
        List *Curr_A =*head,*Curr_B =*head;
        List *temp;
        if(a==b){
            return;
        }
       assert(a);
       assert(b);
       assert(head);

        //while(Curr_ptr != NULL){
                //Last_ptr = Curr_ptr->next; 

                while( Curr_A && Curr_A != a){
                    prev_A = Curr_A;
                    Curr_A = Curr_A->next;
                }
                //if(Curr_ptr->next == b){
                while(Curr_B && Curr_B != b){
                    //printf("b\n");
                    prev_B = Curr_B;
                    Curr_B = Curr_B->next;
                }
                if(prev_A  != NULL){
                    prev_A->next = Curr_B;
                }else{
                    *head = Curr_B;
                }
                if(prev_B  != NULL){
                    prev_B->next = Curr_A;
                }else{
                    *head = Curr_A;
                }   
        temp =  Curr_B->next;
         Curr_B->next = Curr_A->next;
         Curr_A->next = temp;      
                //Curr_ptr = Curr_ptr->next;
        //}
        //return 0;
}
unsigned int GetRandVal(const unsigned int NodeNumber){
        
        //#define GetRandNum(NodeNum)  (rand()%NodeNum)+1
        return (rand()%NodeNumber+1);
}

void Random_shuffle(List *head,const unsigned int NodeNumber){
        
        unsigned int i ;
        unsigned int randnum = GetRandVal(NodeNumber);
        unsigned int Ra,Rb;
        printf("Random_shuffle time %d\n",randnum);
        for(i=0;i<randnum;i++){
                    Ra = GetRandVal(NodeNumber);
                    Rb = GetRandVal(NodeNumber);
                    List *a = GetKeyNode(head,Ra);
                    List *b = GetKeyNode(head,Rb);
                    swap_list(&head,a,b);
        }
}

List  *Init_LinkList(const unsigned int NodeNumber){
        List  *curr , *temp_Head;
       
        unsigned int i;
        temp_Head = LinkListCreate(NodeNumber);
        curr = temp_Head;
        //printf("1. curr %x  val  %d,next %x \n",curr ,curr->val, curr->next);
        for(i = NodeNumber-1;i > 0; i--){
                //curr->next = LinkListCreate(i);
                List *tmp = LinkListCreate(i);
                insert_node(curr,tmp);
                curr = curr->next;
        }
        Random_shuffle(&temp_Head,NodeNumber);
        //printf("temp_Head %x \n",temp_Head);
        return temp_Head;
}

List  *GetTrailNode(const List *head){
    List *curr = head;
    while(curr != NULL){
        curr = curr->next;
    }
    return curr;
}



void ShowAllOfNode(const List **head){
        List  *curr = head;
        printf("Node val: ");
        do{
                printf("%d,",curr->val );
                curr = curr->next;
        }while(curr != NULL);
        printf("\n" );
}

List* bubblesort(const List **head)    //pointer to pointer
{
    unsigned char flag = true;
    while(flag) {
        List* current = *head;
        List* prev = NULL;
        flag = false;
        while(current != NULL && current->next !=NULL) {
            if (current->val > current->next->val) {
                flag = true;
                swap_list(head,current,current->next);
            }
            current = current->next;         
        }
    }
    return head;
}

int main (int argc , char const *argv[]){
        srand(time(NULL));
        if(argc == 1){
            printf("please input node number\n");
            return -1;
        }
        const unsigned int NodeNum = atoi(argv[1]);
        List *head  = Init_LinkList(NodeNum);
        ShowAllOfNode(head);
        bubblesort(&head);
        ShowAllOfNode(head);
        return 0;
}