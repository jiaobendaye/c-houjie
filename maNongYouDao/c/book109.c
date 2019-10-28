/* 
 *  此程序演示文件打开和关闭
 *  作者：豫让 日期：20190601
*/
#include <stdio.h>
#include <string.h>

int main()
{
  FILE *fp=0;     // 定义文件指针变量fp

  // 以只读的方式打开文件/oracle/c/book1.c
  printf("%p\n",(fp=fopen("/oracle/c/book1.c","r")));
  
  // 关闭文件
  if ( fp!=0 ) fclose(fp);

  return 0;
}


