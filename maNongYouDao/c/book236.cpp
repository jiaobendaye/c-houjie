/* 
 *  此程序演示用类的多态
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

  virtual int  Show()=0;       // 申明显示基本信息的方法

  /*
  virtual int  Show()       // 申明显示超女基本信息的成员函数
  {  // 虚函数
    printf("姓名：%s，年龄：%d，身高：%d，身材：%s，颜值：%s\n",\
            m_name,m_age,m_height,m_sc,m_yz);
  }
  */
};

class CKCon:public CGirl   // 定义王妃类，从超女类继承
{
public:
  char m_ch[50];      // 称号
  char m_palace[50];  // 居住的宫殿
  int  m_sal;         // 奉禄
 
  int  Show()         // 申明显示王妃基本信息的成员函数
  {
    printf("称号：%s，年龄：%d，身高：%d，身材：%s，颜值：%s\n",\
            m_ch,m_age,m_height,m_sc,m_yz);
  }
};

int main()
{
  CKCon KCon;
  strcpy(KCon.m_name,"杨玉环");
  KCon.m_age=28;      
  KCon.m_height=168;
  strcpy(KCon.m_sc,"火辣");
  strcpy(KCon.m_yz,"漂亮");
  strcpy(KCon.m_ch,"杨贵妃");
  strcpy(KCon.m_palace,"华清宫");
  KCon.m_sal=10000;

  CGirl *p1;   // 基类的指针
  CKCon *p2;   // 派生类的指针

  p1=p2=&KCon;  // 都指向派生类

  p1->Show();   // 将调用的是基类的Show方法
  KCon.Show();   // 将调用的是派生类的Show方法
}

