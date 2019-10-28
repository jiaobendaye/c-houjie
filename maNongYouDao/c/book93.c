/* 
 *  此程序演示结构体的指针
 *  作者：豫让 日期：20190525
*/
#include <stdio.h>
#include <string.h>

struct st_girl
{
  char name[50];     // 姓名
  int  age;          // 年龄
};

int main()
{
  struct st_girl *pst,queen;  // 定义结构体变量
  
  // 初始化结构体变量
  memset(&queen,0,sizeof(struct st_girl));

  pst=&queen;

  // 对结构体每个成员赋值
  strcpy(pst->name,"武则天");
  pst->age=28;

  printf("姓名：%s，年龄：%d\n",queen.name,queen.age);
  printf("姓名：%s，年龄：%d\n",pst->name,pst->age);
  printf("姓名：%s，年龄：%d\n",(*pst).name,(*pst).age);
}


