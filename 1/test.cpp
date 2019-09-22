#include <iostream>
#include "string"
#include "complex"

String c3("aslkdjf"); // global object
void main()
{
  String s1();//use stack, stack object (local/ auto object),only live in this scope ,will be auto destroied 
  String s2("hello");
  static String("hello");//
  String s3(s1);
  cout << s3 << endl;
  
  s3 = s2;
  String* ps = new String("world");//use system heap, you have to delete it by yourslef

/*
void* mem = operator new( sizeof(String));//malloc(n)
p = static_cast<String*>(mem);
p->String::String("world");
*/
  delete ps;
/*
String::~String(p);
operator delete(p);// free(p)
*/
  Complex* pc = new Complex(1,2);
/*
debug mod:8+(32+4)+(4*2) => 52 => padding ==> 64 byte
no debug: 8+(4*2) => 16
*/
  Complex* pca = new Complex[3];//array
  delete[] pca
/*
51h (4) -> debugger Header(32) -> 3(4)-> double *8 (8*3) -> no man land (4)-> padding *2 (8)-> 51h (4)
(8*3) + (32+4) + (4*2) + 4 = 72 ==>padding=> 80

*/ 
  String* psa = new String[3];
  //when there is pointer in class, you have to delete all the  memory you allocated 
  delete [] psa //wake up dtor 3 times

}


