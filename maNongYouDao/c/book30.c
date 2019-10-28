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

  switch (day)
  {
    case 0: printf("星期天\n"); break;
    case 1: printf("星期一\n"); break;
    case 2: printf("星期二\n"); break;
    case 3: printf("星期三\n"); break;
    case 4: printf("星期四\n"); break;
    case 5: printf("星期五\n"); break;
    case 6: printf("星期六\n"); break;
    default: printf("输入错误。\n"); break;
  }

  return 0;
}

