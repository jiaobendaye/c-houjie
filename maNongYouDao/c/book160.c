/* 
 *  此程序演示errno全局变量和strerror函数
 *  作者：豫让 日期：20190601
*/
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
  FILE *fp=0;     // 定义文件指针变量fp

  // 以只读的方式打开文件/oracle/c/book1.c
  if ( (fp=fopen("/oracle/c/book1.ccc","r")) == 0 )
  {
    printf("打开文件%s失败（%d：%s）。\n","/oracle/c/book1.ccc",errno,strerror(errno)); 
  }
  
  // 关闭文件
  if ( fp!=0 ) fclose(fp);

  return 0;
}


