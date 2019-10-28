/* 
 *  此程序演示main函数的参数
 *  作者：豫让 日期：20190525
*/
#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
  int ii=0;

  // 显示参数的个数
  printf("argc is %d\n",argc);

  // 列出全部的参数
  for (ii=0;ii<argc;ii++)
  {
    printf("argv[%d] is %s\n",ii,argv[ii]);
  }
}


