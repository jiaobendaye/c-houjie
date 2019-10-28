/*
 *  此程序演示for循环语句
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 

int main () 
{ 
  int ii=0;         // 楼层编号计数器
  int jj=0;         // 房间编号计数器

  for (ii=1;ii<=3;ii++)
  {
    for (jj=1;jj<=4;jj++)
    {
       printf("这是第%d层楼的第%d个房间。\n",ii,jj);
    }
  }

  return 0;
}
     

