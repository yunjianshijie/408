#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int row_index;
	int col_index;
	int value;
}Node;
typedef struct STable{
	Node data[20];
	int index;
	int row_count;
	int col_count;
}STable;
STable * create_table(int row_count,int col_count){
	STable * st = (STable *)malloc(sizeof(STable));
	st->row_count = row_count;
	st->col_count = col_count;
	st->index = 0;
	return st;
}
void add(int v,int row_index,int col_index,STable * st){
	st->data[st->index].value = v;
	st->data[st->index].col_index = col_index;
	st->data[st->index].row_index = row_index;
}
//恢复
int* * restore(STable * st){
	//需要一个矩阵
	int ** result = (int **)malloc(sizeof(int*)*st->row_count);
	for(int i=0;i<st->row_count;i++){
		result[i] = (int *)malloc(sizeof(int)*st->col_count);
		for(int j = 0;j<st->col_count;j++){
			result[i][j] = 0;
		}
	}
	for(int i=0;i<st->index;i++){
		int row  = st->data[i].row_index;
		int col  = st->data[i].col_index;
		result[row][col] = st->data[i].value;
	}
	return result;
}
