/*
*  此程序演示数组的地址
*  作者：豫让 日期：20190525
*/
#include <stdio.h>
#include <string.h>

int main()
{
  // 定义字符串并初始化
  char str[21];   
  memset(str,0,sizeof(str));
  strcpy(str,"豫让");

  printf("字符串数组的地址是：%p\n",str); 
  printf("字符串的值：%s\n",str);    

  return 0;
}


