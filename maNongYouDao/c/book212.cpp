/* 
 *  此程序演示引用
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 

void func(int *a) // a是一个指针变量
{ *a=20; }

void func(int &a) // a是一个引用
{ a=30; }

int main () 
{ 
  int a=0;

  func(&a);  // 传递变量的地址
  printf("1 a=%d\n",a);

  func(a);   // 引用
  printf("2 a=%d\n",a);
}



