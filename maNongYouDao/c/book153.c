/* 
 *  此程序演示#ifdef条件编译
 *  作者：豫让 日期：20190601
*/
#include <stdio.h>

#define LINUX  

int main()
{
  #ifdef LINUX
    printf("这是Linux操作系统。\n");
  #else
    printf("未知的操作系统。\n");
  #endif
}


