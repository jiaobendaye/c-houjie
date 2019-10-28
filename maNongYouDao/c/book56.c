/* 
 *  此程序演示空指针
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 

int main () 
{ 
  int *pi=0;  // 定义一个指针

  printf("pi的值是 %p\n",pi);

  *pi=10;  // 对指针指向的内存赋值

  printf("*pi的值是 %d\n",*pi);

  return 0;
}


