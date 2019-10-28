/*
 *  此程序演示全局变量的使用
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 

double pi=3.141592; // 全局变量声明

void func1(); // 声明一个自定义函数

int main () 
{ 
  //printf("位置一 pi=%f\n",pi);

  func1();

  //printf("位置二 pi=%f\n",pi);
}

void func1()
{
  printf("位置三 pi=%f\n",pi);
  pi=3.141593;  // 改变pi的值
  printf("位置四 pi=%f\n",pi);
}


