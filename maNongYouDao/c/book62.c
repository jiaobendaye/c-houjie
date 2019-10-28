/* 
 *  此程序演示小数与整数的转换，包括取整 round ceil floor函数的使用                      
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 
#include <math.h>

int main () 
{ 
  double dd=1258.53;

  int ii = (int)dd;      // 强制转换，直接取整，小数扔掉
  int jj = round(dd);    // 四舍五入取整
  int kk = ceil(dd);     // 向上取整
  int ll = floor(dd);    // 向下取整
 
  printf("ii=%d\n",ii);
  printf("jj=%d\n",jj);
  printf("kk=%d\n",kk);
  printf("ll=%d\n",ll);

  return 0;
}



