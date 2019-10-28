/* 
 *  此程序演示结构体
 *  作者：豫让 日期：20190525
*/
#include <stdio.h>
#include <string.h>

struct st_girl
{
  char name[50];     // 姓名
  int  age;          // 年龄
  int  height;       // 身高，单位：厘米cm
  char sc[30];       // 身材，火辣；普通；飞机场。
  char yz[30];       // 颜值，漂亮；一般；歪瓜裂枣。
};

void main()
{
  struct st_girl stgirl;
  printf("%d\n",stgirl);   // 没有意义
  printf("%p\n",stgirl);   // 没有意义
  printf("%p\n",&stgirl);  // 这是结构体的地址
}


//  printf("sizeof(struct st_girl) %d\n",sizeof(struct st_girl));
