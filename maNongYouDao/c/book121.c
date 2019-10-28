/* 
 *  此程序演示动态内存分配
 *  作者：豫让 日期：20190601
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_girl  // 超女结构体
{
  char name[50];     // 姓名
  int  age;          // 年龄
};

int main(int argc,char *argv[])
{
  int    *pi=malloc(sizeof(int));    // 分配int类型大小的内存
  long   *pl=malloc(sizeof(long));   // 分配long类型大小的内存
  double *pd=malloc(sizeof(double)); // 分配double类型大小的内存
  char   *pc=malloc(101);            // 分配101字节的内存，可存放100个字符的字符串
  // 分配struct st_girl结构体大小的内存
  struct st_girl *pst=malloc(sizeof(struct st_girl));

  // 以下代码是像普通指针和变量一样使用动态分配的内存
  *pi=10;     printf("*pi=%d\n",*pi);
  *pl=20;     printf("*pl=%d\n",*pl);
  *pd=10.5;   printf("*pd=%.1f\n",*pd);
  strcpy(pc,"西施"); printf("*pc=%s\n",pc);
  strcpy(pst->name,"杨玉环"); pst->age=21;
  printf("name=%s,age=%d\n",pst->name,pst->age);
  
  // 释放动态分配的内存
  free(pi); free(pl); free(pd); free(pc); free(pst);
}


