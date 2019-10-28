/* 
 *  此程序演示整数占用内存的大小和取值范围
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 
#include <math.h>
#include <stdlib.h> 

int main () 
{ 
  short si;   // 短整数
  int   ii;   // 整数
  long  li;   // 长整数

  printf("sizeof signed short is %d\n",sizeof(signed short));
  printf("sizeof unsigned short is %d\n",sizeof(unsigned short));

  printf("sizeof signed int is %d\n",sizeof(signed int));
  printf("sizeof unsigned int is %d\n",sizeof(unsigned int));

  printf("sizeof signed long is %d\n",sizeof(signed long));
  printf("sizeof unsigned long is %d\n",sizeof(unsigned long));

  return 0;
}



