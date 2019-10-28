/* 
 *  此程序演示函数参数的传递和指针                                              
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 

// 声明func函数，p是一个指针变量
void func(int *p);   

int main () 
{ 
  int a=10;

  printf("位置一a的地址是   %p，a的值是 %d\n",&a,a);
  func(&a);   // 调用函数，传递变量a的地址的值
  printf("位置二a的地址是   %p，a的值是 %d\n",&a,a);
}

void func(int *p)
{
  printf("位置三p是一个指针 %p, 地址指向的内存的值是 %d\n",p,*p);
  *p=20;   
  printf("位置四p是一个指针 %p, 地址指向的内存的值是 %d\n",p,*p);
}


