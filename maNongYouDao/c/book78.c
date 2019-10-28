/* 
 *  此程序测试浮点数据的科学计数法
 *  作者：豫让 日期：20190525
*/

#include <stdio.h>

int main()
{
  double dd;

  dd=123000000;        
  printf("dd is  %.2e\n",dd);

  dd=-123000000;        
  printf("dd is %.2e\n",dd);

  dd=0.0000000123;        
  printf("dd is  %.2e\n",dd);

  dd=-0.0000000123;        
  printf("dd is %.2e\n",dd);                     

  return 0;
}

