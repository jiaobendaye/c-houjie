/* 
 *  此程序测试double的特征
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 

int main()
{
  double ff2=9.9;   // 测试2位的浮点数
  printf("ff2=%f\n",ff2);
  if (ff2==9.9) printf("ff2与9.9相等。\n");

  double ff12=999999999.99;   // 测试12位的浮点数
  printf("ff12=%f\n",ff12);
  if (ff12==999999999.99) printf("ff12与999999999.999相等。\n");

  double ff13=9999999999.99;   // 测试13位的浮点数
  printf("ff13=%f\n",ff13);
  if (ff13==9999999999.99) printf("ff13与9999999999.999相等。\n");

  double ff14=99999999999.99;   // 测试14位的浮点数
  printf("ff14=%f\n",ff14);
  if (ff14==99999999999.99) printf("ff14与99999999999.999相等。\n");

  double ff15=999999999999.99;   // 测试15位的浮点数
  printf("ff15=%f\n",ff15);
  if (ff15==999999999999.99) printf("ff15与999999999999.999相等。\n");

  double ff16=9999999999999.99;   // 测试16位的浮点数
  printf("ff16=%f\n",ff16);
  if (ff16==9999999999999.99) printf("ff16与9999999999999.999相等。\n");

  double ff17=99999999999999.99;   // 测试17位的浮点数
  printf("ff17=%f\n",ff17);
  if (ff17==99999999999999.99) printf("ff17与99999999999999.999相等。\n");

  double ff18=999999999999999.99;   // 测试17位的浮点数
  printf("ff18=%f\n",ff18);
  if (ff18==999999999999999.99) printf("ff17与99999999999999.999相等。\n");
  return 0;
}


