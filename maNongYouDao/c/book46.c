/* 
 *  此程序演示函数的声明和定义                                          
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 
#include "_public.h"  // 把_public.h头文件包含进来

long   ATOL(const char *nptr);  

int main () 
{ 
  printf("%d\n",ctoi('/'));
  printf("%d\n",ctoi('0'));
  printf("%d\n",ctoi('1'));
  printf("%d\n",ctoi('2'));
  printf("%d\n",ctoi('3'));
  printf("%d\n",ctoi('4'));
  printf("%d\n",ctoi('5'));
  printf("%d\n",ctoi('6'));
  printf("%d\n",ctoi('7'));
  printf("%d\n",ctoi('8'));
  printf("%d\n",ctoi('9'));
  printf("%d\n",ctoi(':'));
}

long   ATOL(const char *nptr)
{
  int len=0;

  while (nptr[len]!=0) len++;     // 计算字符串的长度

  int pos=0;
  long sum=0;

  for (pos=0;pos<len;pos++) 
  {
    sum=sum+ctoi(nptr[pos])*POW(10,len-pos-1);
  }
  
  return sum;
}
