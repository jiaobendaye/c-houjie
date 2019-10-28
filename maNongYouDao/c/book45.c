/* 
 *  此程序演示自定义函数在主程序中声明和定义                                          
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 

// 判断超女身材的函数checksc的声明
// 参数height是身高，单位厘米
// 返回值：-1-不合格；1-娇小；2-标准；3-高挑
int checksc(int height);

int main () 
{ 
  int ii,jj;

  printf("请输入超女的身高（单位：厘米）：");
  scanf("%d",&ii);

  jj=checksc(ii);   // 调用checksc函数判断身材

  if (jj==-1) printf("不合格。\n");
  if (jj== 1) printf("娇小。\n");
  if (jj== 2) printf("标准。\n");
  if (jj== 3) printf("高挑。\n");
}

// checksc的定义
int checksc(int height)
{
  if ( (height<160) || (height>=180) ) return -1; // 不合格
  if ( (height>=160) && (height<165) ) return  1; // 娇小
  if ( (height>=165) && (height<175) ) return  2; // 标准
  if ( (height>=175) && (height<180) ) return  3; // 高挑
}

