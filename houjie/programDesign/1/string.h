#ifndef __MYSTRING__
#define __MYSTRING__

//1
class String
{
public:
   String(const char* cstr = 0);//constructor
   String(const String& str); //copy and constructor s2(s1);
   String& operator=(const String& str);//copy and asignment op s2 = s1;
   ~String();
   char* get_c_str() const { return m_data;}
private:
   char* m_data;

};
//2-1
inline 
String::String(const char* cstr = 0)
{
    if (cstr) {
	m_data = new char[strlen(cstr)+1];//array new
	strcpy(m_data, cstr);
    }
    else {
	m_data = new char[1];
	*m_data = '\0';
    }
}
inline 
String::~String()
{
   delete [] m_data;//array delete
}
//2-2 String s2 = s1
inline 
String::String(const String& str)
{
   m_data = new char[ strlen(str.m_data) + 1];
   strcpy(m_data, str.m_data);
}
//2-3 s2 = s1
inline 
String& String::operator=(const String& str)
{
   if (this == &str) return *this;

   delete[] m_data;
   m_data = new char[ strlen(str.m_data) + 1];
   strcpy(n_data, str.m_data);
   return *this;
}
//2-4
#include <iostream.h>
ostream& 
operator<<(ostreams& os, const String& str)
{
   os << str.get_c_str();
   return os;
}
#endif

