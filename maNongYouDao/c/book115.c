/* 
 *  此程序演示二进制文件的写入
 *  作者：豫让 日期：20190601
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
  struct st_girl stgirl;  // 定义超女数据结构变量
  FILE *fp=0;     // 定义文件指针变量fp

  // 以只写的方式打开文件/tmp/test1.dat
  if ( (fp=fopen("/tmp/test1.dat","wb")) == 0) 
  {
    printf("fopen(/tmp/test1.dat) failed.\n"); return -1;
  }

  // 为超女数据结构的成员赋值
  strcpy(stgirl.name,"西施"); stgirl.age=18; stgirl.height=170;
  strcpy(stgirl.sc,"火辣"); strcpy(stgirl.yz,"漂亮");

  // 把超女数据结构写入文件
  fwrite(&stgirl,1,sizeof(struct st_girl),fp);
  
  // 关闭文件
  fclose(fp);
}


