/* 
 *  此程序演示结构体作为函数的参数
 *  作者：豫让 日期：20190525
*/
#include <stdio.h>
#include <string.h>

struct st_girl
{
  char name[50];     // 姓名
  int  age;          // 年龄
};

// 对结构体赋值的函数
void setvalue(struct st_girl *pst);

int main()
{
  struct st_girl queen;  // 定义结构体变量
  
  // 初始化结构体变量
  memset(&queen,0,sizeof(struct st_girl));

  setvalue(&queen);  // 调用函数，传结构体的地址

  printf("姓名：%s，年龄：%d\n",queen.name,queen.age);
}

void setvalue(struct st_girl *pst)
{
  // 对结构体每个成员赋值
  strcpy(pst->name,"武则天");
  pst->age=28;
}
