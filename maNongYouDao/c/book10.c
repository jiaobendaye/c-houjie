/*
 *  此程序演示局部变量的初始化
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 
#include <string.h>

int main () 
{ 
  int   ii;         // 定义整数型变量
  char  cc;         // 定义字符型变量
  double money;     // 定义浮点型变量
  char name[20];    // 定义字符串变量

  ii=0;      // 整数型变量初始化
  cc=0;      // 字符型变量初始化
  money=0;   // 浮点型变量初始化
  memset(name,0,sizeof(name));  // 字符串初始化

  printf("ii=%d=\n",ii);
  printf("cc=%c=\n",cc);
  printf("money=%f=\n",money);
  printf("name=%s=\n",name);
}

