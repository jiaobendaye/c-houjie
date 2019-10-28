/* 
 *  此程序演示string类
 *  作者：豫让 日期：20190525                             
*/
#include <stdio.h> 
#include <string.h>
#include <string>

using namespace std;

int main () 
{ 
  std::string str1;

  str1="hello world";

  char str2[31];

  strcpy(str2,str1.c_str());

  printf("str2=%s\n",str2);

  str1.clear();

  printf("%d\n",str1.size());
  printf("%d\n",str1.length());

  printf("str1=%s\n",str1.c_str());
}



