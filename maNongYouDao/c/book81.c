/* 
 *  此程序演示strncpy函数的缺陷
 *  作者：豫让 日期：20190525
*/
#include <stdio.h>
#include <string.h>

int main()
{
  char dest[30];

  memset(dest,0,sizeof(dest));
  strncpy(dest,"abcdefgh",5);
  printf("1=%s=\n",dest);

  memset(dest,0,sizeof(dest));
  strcpy(dest,"abcdefgh");
  printf("2=%s=\n",dest);

  memset(dest,0,sizeof(dest));
  strncpy(dest,"abcdefgh",5);
  printf("3=%s=\n",dest);

  memset(dest,0,sizeof(dest));
  strncpy(dest,"abcd",5);
  printf("4=%s=\n",dest);
}


