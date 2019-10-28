/*
  此程序用于演示C程序的基本结构
  作者：豫让 日期：20190525
*/
#include <stdio.h> 
#include <string.h> 

// 定义全局变量，存放了当前的月份。
int iMonth=5;

// 子函数childfunc的定义
int childfunc();

int main() 
{ 
   char name[50];  // 定义局部变量，存放姓名

   strcpy(name,"豫让");   // 给name赋值"豫让"

   // 请用一句话表达你要成为程序员的决心。
   printf("%s：我心非石，不可转也；我心非席，不可卷也。\n",name); 

   // 调用子函数childfunc
   childfunc();

   return 0; 
}

// 子函数childfunc的函数体
int childfunc()
{
  printf("现在是%d月份，这是我的第一个子函数，哦嘢。\n",iMonth);

  return 0;
}
