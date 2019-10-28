/* 
 *  此程序演示用函数重载的方法修复strcpy函数的缺陷
 *  作者：豫让
 *  日期：20190525
*/
#include <stdio.h>
#include <string.h>

// 重载strcpy函数，对dest初始化，防止内存溢出
char *strcpy(char *dest, const char *src,size_t destlen)
{
  memset(dest,0,destlen);  // 对dest初始化

  // 计算需要复制的字符数，不能超出destlen-1
  size_t len=0;
  if (strlen(src)<=destlen-1) len=strlen(src);
  else len=destlen-1;

  strncpy(dest,src,len);   // 复制字符串，超出的将扔掉
  dest[len]=0;  // 强制字符串的结尾标志

  return dest;
}

int main()
{
  char dest[10];

  strcpy(dest,"abcdefghijklmn",sizeof(dest));  // 新strcpy
  printf("=%s=\n",dest);

  strcpy(dest,"abcdefghijklmn");   // 旧strcpy
  printf("=%s=\n",dest);
}

