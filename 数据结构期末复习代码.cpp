#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

//算法有 有穷性，确定性，可行性，输入，输出 
//好算法的目标 ： 正确性，可读性，健壮性，效率与低储存需求

//算法效率的度量 事后统计，事前分析
//时间复杂度，空间复杂度

//线性表复习

#define LIST_INIT_SIZE 100 //线性表存储空间的初始分配量
#define LISTINCREMENT 10  //线性表存储空间的分配增量
#define char ElemType;

typedef struct Sqlist{
    ElemType *elem; //存储空间基址
    int length;
    int listsize;
}Sqlist_0;

Sqlist Sqlist_1;

//1069070069
