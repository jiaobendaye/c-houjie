/*
 *  此程序演示printf函数输出数据
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 
#include <string.h>

int main () 
{ 
  int age=18;
  char xb='x';
  double weight=62.5;

  char name[21];
  memset(name,0,sizeof(name));
  strcpy(name, "豫让");

  printf("我的姓名是：%s，姓别：%c，年龄：%d岁，体重%f公斤。\n",name,xb,age,weight);

  return 0;
}


