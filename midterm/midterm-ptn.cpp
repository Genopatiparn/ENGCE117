// patiparn sangkad 655432068-0 sec3
// URL : https://www.youtube.com/watch?v=KKmuSXu-RdQ&ab_channel=patiparnsangkad

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int gn;
    struct Node *next; 
};

void ShowAll( struct Node *walk );
struct Node *AddNode( struct Node **walk, int gn );
void UpdateNode(struct Node **walk, int ps, int sk);
struct Node *ShowBack(struct Node **walk);
void SwapNode(struct Node **walk, int ptn, int snk);

int main(){
    struct Node *start = NULL;
    AddNode( &start, 55 ); 
    AddNode( &start, 66 );   
    AddNode( &start, 77 ); 
    AddNode( &start, 88 );
    ShowAll(start);
    UpdateNode (&start, 88 , 11);
    ShowAll(start);
  	ShowBack(&start);
    ShowAll(start);
    SwapNode(&start, 77, 66);
    ShowAll(start);
	return 0;
}

void ShowAll( struct Node *walk ){
    while (walk != NULL){
        printf("%d ", walk->gn); 
        walk = walk->next; 
    } 
    printf("\n");
}
struct Node *AddNode( struct Node **walk, int gn ){ 
    while(*walk != NULL){
        walk = &(*walk)->next;
    }
    *walk = new struct Node;
    (*walk)->gn = gn;
    (*walk)->next = NULL;
    return *walk;
}
void UpdateNode(struct Node **walk, int ps, int sk){
    struct Node *temp = *walk;
    while(temp != NULL){
        if(temp->gn == ps){
            temp->gn = sk;
            break;
        }
        temp = temp->next;
    }
}
struct Node *ShowBack(struct Node **walk) {
  if (walk == NULL) {
    return NULL;
  }
  	struct Node *open = NULL;
    struct Node *current = *walk;
    struct Node *next = NULL;
    while (current != NULL) {   
        next = current->next;
        current->next = open;
        open = current;
        current = next;
    }
    *walk = open;
    return *walk;
}
void SwapNode(struct Node **walk, int ptn, int snk){
    struct Node *how = *walk;
    struct Node *dis = *walk;
    int temp;
    while(how != NULL && how->gn != ptn){
        how = how->next;
    }
    while(dis != NULL && dis->gn != snk){
        dis = dis->next;
    }
    if(how == NULL || dis == NULL){
        return;
    }
    temp = how->gn;
    how->gn = dis->gn;
    dis->gn = temp;
}   
