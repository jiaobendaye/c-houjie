/* 
 *  此程序演示main函数的参数
 *  作者：豫让 日期：20190525
*/
#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[],char *envp[])
{
  int ii = 0;

  while (envp[ii] != 0)  // 数组最后一个元素是0
  {
    printf("%s\n",envp[ii]); ii++;
  }
}


