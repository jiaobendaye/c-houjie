/*
 *  此程序演示采用for循环语句和数组结合使用
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 

int main () 
{ 
  int    ii=0;           // 用于循环的计数器
  int    total=5;        // 超女的总人数，初始化为5
  double weight[total];  // 定义数组，用于存放超女的体重
  double sum=0;          // 存放超女体重的和
  
  memset(weight,0,sizeof(weight));    // 初始化数组为0

  // 循环输入超女的体重，并计算体重的总和
  for (ii=0;ii<total;ii++)
  {
    printf("请输入第%d名超女的体重：",ii+1);   // 输入提示信息
    scanf("%lf",&weight[ii]);    // 接受从键盘输入的体重
    sum=sum+weight[ii];          // 计算超女体重的和
  }

  printf("超女的平均体重是：%lf\n",sum/total);  // 输出平均体重
}


