/* 
 *  此程序演示string类的字符串的地址
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 
#include <string>

int main () 
{ 
  std::string str;

  str="中华人民共和国";
  printf("%p\n",str.c_str());

  str=str+"aaaaa";
  printf("%p\n",str.c_str());

  str="ccccc";
  printf("%p\n",str.c_str());

  str="aaaaaaaaaaaaaaaacccccccccccccaaaabccccccc";
  printf("%p\n",str.c_str());
}



