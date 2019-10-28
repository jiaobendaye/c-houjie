/* 
 *  此程序演示strcat和strncat函数是否有缺陷
 *  作者：豫让 日期：20190525
*/
#include <stdio.h>
#include <string.h>

int main()
{
  char dest[30];

  memset(dest,'c',sizeof(dest)); dest[2]=0;
  strncat(dest,"abcdefgh",5);
  printf("1=%s=%c\n",dest,dest[15]);

  memset(dest,'c',sizeof(dest)); dest[2]=0;
  strcat(dest,"abcdefgh");
  printf("2=%s=%c\n",dest,dest[15]);

  memset(dest,'c',sizeof(dest)); dest[2]=0;
  strncat(dest,"abcdefgh",5);
  printf("3=%s=%c\n",dest,dest[15]);

  memset(dest,'c',sizeof(dest)); dest[2]=0;
  strncat(dest,"abcd",5);
  printf("4=%s=%c\n",dest,dest[15]);
}

