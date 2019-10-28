/*
*  此程序演示指针的运算
*  作者：豫让 日期：20190525
*/
#include <stdio.h>
#include <string.h>

int main()
{
  char   cc[4];   // 字符数组
  int    ii[4];   // 整数数组
  double dd[4];   // 浮点数组

  // 用地址相加的方式显示数组全部元素的的址
  printf("%p %p %p %p\n",cc,cc+1,cc+2,cc+3);
  printf("%p %p %p %p\n",ii,ii+1,ii+2,ii+3);
  printf("%p %p %p %p\n",dd,dd+1,dd+2,dd+3);

  return 0;
}


