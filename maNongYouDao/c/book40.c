/*
 *  此程序演示没有数组的多个变量
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 

int main () 
{ 
  double aa,bb,cc,dd,ee;  // 定义5个变量存放5名超女的体重
  aa=bb=cc=dd=ee=0;

  printf("请输入第1名超女的体重（公斤）：");
  scanf("%lf",&aa);
  printf("请输入第2名超女的体重（公斤）：");
  scanf("%lf",&bb);
  printf("请输入第3名超女的体重（公斤）：");
  scanf("%lf",&cc);
  printf("请输入第4名超女的体重（公斤）：");
  scanf("%lf",&dd);
  printf("请输入第5名超女的体重（公斤）：");
  scanf("%lf",&ee);

  printf("超女的平均体重是：%lf\n",(aa+bb+cc+dd+ee)/5); 
}


