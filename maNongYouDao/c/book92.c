/* 
 *  此程序演示结构体的使用
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

int main()
{
  struct st_girl queen;  // 定义结构体变量
  
  // 初始化结构体变量
  memset(&queen,0,sizeof(struct st_girl));

  // 对结构体每个成员赋值
  strcpy(queen.name,"武则天");
  queen.age=28;
  queen.height=168;
  strcpy(queen.sc,"火辣");
  strcpy(queen.yz,"漂亮");

  printf("姓名：%s\n",queen.name);
  printf("年龄：%d\n",queen.age);
  printf("身高：%d\n",queen.height);
  printf("身材：%s\n",queen.sc);
  printf("颜值：%s\n",queen.yz);
}


