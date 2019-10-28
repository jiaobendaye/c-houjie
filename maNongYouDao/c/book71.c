/* 
 *  此程序测试float、double和long double占用内存的字节数
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 

int main()
{
  printf("sizeof float is %d\n",sizeof(float));
  printf("sizeof double is %d\n",sizeof(double));
  printf("sizeof long double is %d\n",sizeof(long double));

  return 0;
}


