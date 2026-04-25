// #include <stdio.h>
// #include <stdlib.h>
// typedef struct Node{
//	int value;
//	struct Node * next;
// }Node,Link;
// Node * insert(int v,Node * head){
//	Node * n = (Node *)malloc(sizeof(Node));
//	n->value = v;
//	n->next = NULL;
//	if(head == NULL){
//		return n;
//	}
//	Node * last = head;
//	while(last->next!=NULL){
//		last = last->next;
//	}
//	last->next = n;
//	return head;
// }
// Node * del_value(int v,Node * h){
//	if(h == NULL){
//		return NULL;
//	}
//	if(v == h->value){
//		Node * n = h->next;
//		free(h);
//		return n;
//	}
//	Node * del = h->next;
//	Node * prev = h;
//	while(del!=NULL && del->value!= v){
//		prev = del;
//		del = del->next;
//	}
//	if(del!=NULL){
//		prev->next = del->next;
//		free(del);
//	}
//	return h;
// }
//
// void show(Node * p){
//	printf("show: %d  ",p == NULL);
//	while(p!=NULL){
//		printf("%d ",p->value);
//		p = p->next;
//	}
//	printf("\n");
// }
//
//
//
// int main(){
//	Link * link;
//	link = NULL;
//	link = insert(11,link);
//	link = insert(22,link);
//	link = insert(33,link);
//	link = insert(44,link);
//	show(link);
//	link = del_value(11,link);
//	show(link);
//
// }
//
//
//
//
//
//
//
//
//
