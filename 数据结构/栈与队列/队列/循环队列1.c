#include <stdio.h>
#include <stdbool.h>

#define MaxSzie 3
typedef struct 
{
   int data [MaxSzie];
   int front ,rear; //队首，队尾
   int size ;
} SqQueue;

// 
void InitQueue(SqQueue * q){
   q->front =q->rear =0;
   q->size =0;
}

bool Push(SqQueue * q , int data){
   if(q->size == MaxSzie){
      return false;
   }
   if(q->rear == MaxSzie -1){
      q->data[q->rear] = data;
      q->rear= 0;
      printf("Push%d: %d\n", MaxSzie - 1, data);
      q->size ++;
      return true;
   }
   q->data[q->rear++] = data;// 0 ,1
   printf("Push%d: %d\n",q->rear-1,data);
   q->size ++;
   return true;
}

bool Pop(SqQueue *q ,int * data){
   if(q->size ==0){
      // 判空
      return false;
   }
   if(q->front == MaxSzie -1){
      * data = q->data[q->front];
      q->front =0;
      printf("pop %d:%d\n",MaxSzie -1,*data);
      q->size --;
      return true;
   }

   *data = q->data[q->front++];
   printf("POP %d:%d\n", q->front-1, *data);
   q->size --;
   return true;
}

void show(SqQueue *q ){
   printf("队首：%d ,队尾:%d\n",q->front,q->rear);
   for(int i = q->front ;i<q->rear ;i++){
      printf("%d ",q->data[i]);
   }
   if(q->size >0 && q->front >=q->rear){
      for(int i = q->front ;i <MaxSzie ;i++)
      {
         printf("%d ", q->data[i]);
      }
      for(int i = 0 ;i<q->front ;i++){
         printf("%d ", q->data[i]);
      }
   }
   printf("\n");
}

int main(){
   SqQueue Q;
   InitQueue(&Q);
   Push(&Q,1);
   Push(&Q,2);
   int data;
   Pop(&Q,&data);
   Pop(&Q, &data);
   show(&Q);
   Push(&Q, 3);
   Push(&Q, 4);
   Push(&Q, 5);
   Pop(&Q, &data);
   Pop(&Q, &data);
   Pop(&Q, &data);
   show(&Q);
}