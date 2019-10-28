/* 
 *  此程序演示函数的调用
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 
#include <string.h> 

// 声明func函数，无返回值无参数
void func();   

int main () 
{ 
  printf("即将调用函数。\n");

  func();

  printf("调用函数已完成。\n");

  return 0;
}

void func()
{
  int ii=0;

  for (ii=0;ii<10;ii++)
  {
    sleep(1);    // sleep是C语言的库函数，睡眠
    printf("已经过去了%d秒。\n",ii+1);
  }
}


