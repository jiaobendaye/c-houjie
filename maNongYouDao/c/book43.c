/*
 *  此程序演示数组下标越界的后果                
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 
#include <string.h> 

int main () 
{ 
  int ii=0;
  int sum[5];    // 定义一维数组

  for (ii=0;ii<100;ii++)
  {
    sum[ii]=ii;
  }

  return 0;
}



