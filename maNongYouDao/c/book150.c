/* 
 *  此程序演示带参数的宏
 *  作者：豫让 日期：20190601
*/
#include <stdio.h>

#define MAX(x,y) ((x)>(y)?(x):(y))

int main()
{
  printf("MAX is %d\n",MAX(34,59));
}

