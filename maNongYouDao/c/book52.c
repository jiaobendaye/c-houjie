/* 
 *  此程序演示指针的使用
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 

int main () 
{ 
  int    ii=10;

  int    *pii=0;  // 定义整数型指针并初始化

  pii=&ii;  // 数型指针并指向变量ii

  // 通过指针操作内存变量，改变内存变量的值
  *pii=20;    // 同ii=20;

  printf("pii的值是：%p\n",pii);
  printf("*pii的值是：%d\n",*pii);
  printf("ii的值是：%d\n",ii);
}



