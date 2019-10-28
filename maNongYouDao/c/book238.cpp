/* 
 *  此程序演示用类的基本概念
 *  作者：豫让 日期：20190601
*/
#include <stdio.h>
#include <string.h>

class CGirl    // 定义超女类
{
public:
  char m_name[50];  // 姓名
  int  m_age;       // 年龄
  int  m_height;    // 身高，单位：厘米cm
  char m_sc[30];    // 身材，火辣；普通；飞机场。
  char m_yz[30];    // 颜值，漂亮；一般；歪瓜裂枣。

  virtual int  Show();      // 申明显示超女基本信息的成员函数
};

class CKCon:public CGirl   // 定义王妃类
{
public:
  char m_ch[50];      // 称号
  char m_palace[50];  // 居住的宫殿
  int  m_sal;         // 奉禄
  //int  Show();        // 申明显示超女基本信息的成员函数
};

int main()
{
  CGirl *p;
  CKCon KCon;   // 实例化一个KCon对象
p=&KCon;
  strcpy(p->m_name,"杨玉环");
  p->m_age=28;      
  p->m_height=168;
  strcpy(p->m_sc,"火辣");
  strcpy(p->m_yz,"漂亮");
  //strcpy(p->m_ch,"杨贵妃");
  //strcpy(p->m_palace,"华清宫");
  //p->m_sal=10000;

  p->Show();   // 调用基类对象的成员函数
}

int CGirl::Show()  // 显示超女基本信息的成员函数体
{
  printf("姓名：%s，年龄：%d，身高：%d，身材：%s，颜值：%s\n",\
          m_name,m_age,m_height,m_sc,m_yz);
}

/*
int CKCon::Show()  // 显示超女基本信息的成员函数体
{
  printf("称号：%s，年龄：%d，身高：%d，身材：%s，颜值：%s\n",\
          m_ch,m_age,m_height,m_sc,m_yz);
}
*/

