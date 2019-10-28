/* 
 *  此程序演示string类的字符串的地址
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 
#include <string.h>
#include <string>

int main () 
{ 
  std::string str1;
  str1="hello world";
  
  char str2[31];
  strcpy(str2,str1.c_str());

  printf("%s\n",str2);

}



