/* 
 *  此程序演示运算符重载
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 
#include <string.h>    

class CGirl    // 定义类
{
public:
  char m_name[50];  // 姓名
  char m_sc[30];    // 身材，火辣；普通；飞机场。

  bool operator==(const CGirl &Girl)
  { // 如果两个类的姓名相同，就相等
    if (strcmp(m_name,Girl.m_name)== 0) return true;
    return false;
  }

  bool operator!=(const CGirl &Girl);

};

int main()
{
  CGirl Girl1,Girl2;

  strcpy(Girl1.m_name,"西施");
  strcpy(Girl2.m_name,"东施");
    
  /*
  if (Girl1 == Girl2) printf("Girl1和Girl2是同一个人。\n");
  else printf("Girl1和Girl2不是同一个人。\n");
  */
  
  if (Girl1 != Girl2) printf("Girl1和Girl2不是同一个人。\n");
  else printf("Girl1和Girl2是同一个人。\n");
}


bool CGirl::operator!=(const CGirl &Girl)
{ // 如果两个类的姓名相同，就相等
  if (strcmp(m_name,Girl.m_name)!= 0) return true;
  return false;
}
