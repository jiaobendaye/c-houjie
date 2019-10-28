/* 
 *  此程序演示用类的继承
 *  作者：豫让 日期：20190601
*/
#include <stdio.h>
#include <string.h>

class CGirl    // 定义超女类
{
private:
  char m_name[50];  // 姓名
public:
  int  m_age;       // 年龄
  int  m_height;    // 身高，单位：厘米cm
  char m_sc[30];    // 身材，火辣；普通；飞机场。
  char m_yz[30];    // 颜值，漂亮；一般；歪瓜裂枣。

  void  SetName(const char *name); // 设置超女的姓名
  char *GetName();  // 获取超女的姓名

  int  Show();      // 申明显示超女基本信息的成员函数
};

void CGirl::SetName(const char *name)
{
  strcpy(m_name,name);
}

char *CGirl::GetName()  // 获取超女的姓名
{
  return m_name;
}

class CKCon:public CGirl   // 定义王妃类，从超女类继承
{
public:
  char m_ch[50];      // 称号
  char m_palace[50];  // 居住的宫殿
  int  m_sal;         // 奉禄

  int  Con();
};

int  CKCon::Con()
{
  printf("姓名：%s，称号：%s，住： %s，奉禄：%d两银子。\n",GetName(),m_ch,m_palace,m_sal);

  return 0;
}

int main()
{
  CKCon KCon;   // 实例化一个KCon对象

  KCon.SetName("杨玉环");
  KCon.m_age=28;      
  KCon.m_height=168;
  strcpy(KCon.m_sc,"火辣");
  strcpy(KCon.m_yz,"漂亮");
  strcpy(KCon.m_ch,"杨贵妃");
  strcpy(KCon.m_palace,"华清宫");
  KCon.m_sal=10000;

  //KCon.Show();   // 调用基类对象的成员函数
  
  KCon.Con();
}

int CGirl::Show()  // 显示超女基本信息的成员函数体
{
  printf("姓名：%s，年龄：%d，身高：%d，身材：%s，颜值：%s\n",\
          m_name,m_age,m_height,m_sc,m_yz);
}

