/*
 *  此程序演示条件分支控制语句有多个if嵌套的情况
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 

int main () 
{ 
  int a,b;   // 定义两个整数变量，用于比较大小

  printf("请输入两个数字：");    // 提示用户输入
  scanf("%d %d",&a,&b);              // 接受用户从键盘输入的数据

  if (a == b)      // 两个数相等的情况
  {
    printf("a(%d) 等于 (%d)\n",a,b);
  }
  else             // 两个数不相等的情况
  {
    if (a > b)     // a大于b的情况
    {
      printf("a(%d) 大于 b(%d)\n",a,b);
    }
    else           // 剩下的就是a小于b的情况了
    {
      printf("a(%d) 小于 b(%d)\n",a,b);
    }
  }
}


