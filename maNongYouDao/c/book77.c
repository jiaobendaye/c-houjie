/* 
 *  此程序测试整数与浮点数的转换
 *  作者：豫让 日期：20190525
*/

#include <stdio.h>

int main()
{
  int ii=3;
  int jj=4;
  double dd;

  dd=ii;        // 可以
  printf("dd is %.2lf\n",dd);

  dd=ii/jj;     // 不行
  printf("dd is %.2lf\n",dd);

  dd=(double)ii/jj;  // 可以
  printf("dd is %.2lf\n",dd);

  return 0;
}

