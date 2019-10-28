/* 
 *  此程序演示字符串的越界
 *  作者：豫让 日期：20190525
*/
#include <stdio.h>
#include <string.h>

int main()
{
  char strname1[21];
  memset(strname1,0,sizeof(strname1));
  char strname2[21];
  memset(strname2,0,sizeof(strname2));
  strcpy(strname1,"真的只能存十个汉字吗，多几个行不行？");
  strcpy(strname2,"是的，只能十个，多了不行。");
  printf("=%s=\n",strname1);
  printf("=%s=\n",strname2);

  char strname[2][21];
  memset(strname,0,sizeof(strname));
  strcpy(strname[1],"是的，只能十个，多了不行。");
  strcpy(strname[0],"真的只能存十个汉字吗，多几个行不行？");
  printf("=%s=\n",strname[0]);
  printf("=%s=\n",strname[1]);
}




