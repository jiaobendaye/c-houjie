/* 
 *  此程序演示格式化输出sprintf和snprintf函数
 *  作者：豫让 日期：20190525
*/
#include <stdio.h>
#include <string.h>

int main()
{
  // 定义变量并初始化
  char str[301];

  // 格式化输出到str中
  sprintf(str,"%d,%c,""%f,%s",10,'A',25.97,"一共输入了三个数。");
  printf("%s\n",str);

  // 格式化输出到str中，只截取前14个字符
  snprintf(str,15,"%d,%c,%f,%s",10,'A',25.97,"一共输入了三个数。");
  printf("%s\n",str);
}
