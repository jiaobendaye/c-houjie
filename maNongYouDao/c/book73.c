/* 
 *  此程序测试float的特征
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 

int main()
{
  float ff2=9.9;   // 测试2位的浮点数
  printf("ff2=%f\n",ff2);
  if (ff2==9.9) printf("ff2==9.9\n");

  float ff5=99.999;   // 测试5位的浮点数
  printf("ff5=%f\n",ff5);
  if (ff5==99.999) printf("ff5==99.999\n");

  float ff6=999.999;   // 测试6位的浮点数
  printf("ff6=%f\n",ff6);
  if (ff6==999.999) printf("ff6==999.999\n");

  float ff7=9999.999;   // 测试7位的浮点数
  printf("ff7=%f\n",ff7);
  if (ff7==9999.999) printf("ff7==9999.999\n");

  float ff8=99999.999;   // 测试8位的浮点数
  printf("ff8=%f\n",ff8);
  if (ff8==99999.999) printf("ff8==99999.999\n");

  return 0;
}


