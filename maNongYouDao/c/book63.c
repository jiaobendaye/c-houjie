/* 
 *  此程序演示随机数
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main()
{
  int ii;

  srand(time(0));  // 播下随机种子

  for (ii=0;ii<5;ii++)  // 生成5个随机数
  {
    printf("%d ", rand());  // 获取随机数
  }

  printf("\n");

  return 0;
}


