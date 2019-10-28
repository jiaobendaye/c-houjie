/*
 *  此程序演示条件分支控制语句有多个 if else的情况
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 

int main () 
{ 
  int    day=0;   // 定义一个整数变量用于接受键盘输入的数字

  printf("请输入0-6之间的数字：");    // 提示用户输入
  scanf("%d",&day);              // 接受用户从键盘输入的数据

  if (day == 0)
    printf("星期天\n");
  else if (day == 1)
    printf("星期一\n");
  else if (day == 2)
    printf("星期二\n");
  else if (day == 3)
    printf("星期三\n");
  else if (day == 4)
    printf("星期四\n");
  else if (day == 5)
    printf("星期五\n");
  else if (day == 6)
    printf("星期六\n");
  else
    printf("输入错误。\n");

  return 0;
}

