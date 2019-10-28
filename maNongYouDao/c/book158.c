/*
 *  此程序演示strerror函数的使用
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 
#include <string.h> 

int main() 
{ 
  int errorno;  

  for(errorno=0;errorno<132;errorno++)  
  {
    printf("%d:%s\n",errorno,strerror(errorno));  
  }

  return 0;
}

