/*
     此程序用于演示C程序的数据类型的定义
     作者：豫让 日期：20190525
*/

#include <stdio.h>
#include <string.h>

int main()
{
  char   ch='$';
  int    no=9;
  double sal=100000.55;
  // 注意，如果要存放30个字符，数组的大小应该是30+1
  char   name[31];  

  strcpy(name,"罗纳尔多");        // 对name赋值

  // 输出变量的值，这行代码可以不写
  printf("%s的球衣是%d号，周薪%c%lf。\n",name,no,ch,sal);

  return 0;
}


