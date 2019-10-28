/* 
 *  此程序演示容器存放结构体
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 
#include <string.h>    
#include <vector>       // vector需要的头文件

struct st_girl       // 超女数据结构
{
  char name[50];     // 姓名
  int  age;          // 年龄
};

int main () 
{ 
  struct st_girl stgirl;             // 超女数据结构
  std::vector<struct st_girl> vgirl; // 存放超女结构体的容器

  strcpy(stgirl.name,"西施"); stgirl.age=18;
  vgirl.push_back(stgirl);

  strcpy(stgirl.name,"杨玉环"); stgirl.age=28;
  vgirl.push_back(stgirl);

  strcpy(stgirl.name,"陈圆圆"); stgirl.age=38;
  vgirl.insert(vgirl.begin()+1,stgirl);

  printf("size=%d\n",vgirl.size());

  if (vgirl.empty()==true) printf("1是空的\n");

  vgirl.clear();

  if (vgirl.empty()==true) printf("2是空的\n");

  // 采用数组下标访问容器中的记录
  for (int ii=0;ii<vgirl.size();ii++) 
  { 
    printf("vgirl[%d].name=%s,vgirl[%d].age=%d\n",\
            ii,vgirl[ii].name,ii,vgirl[ii].age);
  }

/*
  // 把容器中的记录复制到结构体
  for (int ii=0;ii<vgirl.size();ii++) 
  { 
    memcpy(&stgirl,&vgirl[ii],sizeof(struct st_girl));
    printf("stgirl.name=%s,stgirl.age=%d\n",stgirl.name,stgirl.age);
  }
*/
}



