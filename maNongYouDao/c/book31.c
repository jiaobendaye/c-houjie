/*
 *  此程序演示while循环语句
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 

int main () 
{ 
  int times=0;   // 记录用户输入数据的次数
  int value=0;   // 用户每次从键盘输入的数据
  int sum=0;     // 记录用户输入数据的和

  while (sum<5000)  // 如果sum的值小于5000，进入循环
  {
    printf("请输入数字：");    // 提示用户输入
    scanf("%d",&value);        // 接受用户从键盘输入的数据

    times++;                   // 用户输入数据的次数自增1
    sum=sum+value;             // 记录用户输入数据的和
  }

  printf("你一共输入了%d个数据，和为%d。\n",times,sum);
}
     
