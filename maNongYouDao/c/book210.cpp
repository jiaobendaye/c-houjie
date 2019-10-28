/* 
 *  此程序演示用类的更多知识
 *  作者：豫让 日期：20190601
*/
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

// 文件操作类声明
class CFile
{
private:
  FILE *m_fp;        // 文件指针
  bool  m_bEnBuffer; // 是否启用缓冲区，true-启用；false-不启用
  char  m_filename[301]; // 文件名

public:
  CFile();   // 类的构造函数
  CFile(bool bEnBuffer);   // 类的构造函数

 ~CFile();   // 类的析构函数

  void EnBuffer(bool bEnBuffer=true);  // 启、禁用缓冲区

  // 打开文件，参数与fopen相同，打开成功true，失败返回false          
  bool Open(const char *filename,const char *openmode);

  // 调用fprintf向文件写入数据
  void Fprintf(const char *fmt, ... );

  // 调用fgets从文件中读取一行
  bool Fgets(char *strBuffer,const int ReadSize);

  // 关闭文件指针
  void Close();
};

int main()
{
  CFile File;

  if (File.Open("/oracle/c/book1.c","r")==false) return -1;
  
  char strLine[301];

  while (true)
  {
    if (File.Fgets(strLine,300)==false) break;

    printf("%s",strLine);
  }

  return 0;
}

CFile::CFile()   // 类的构造函数
{
  m_fp=0;
  m_bEnBuffer=true;
  memset(m_filename,0,sizeof(m_filename));
}

CFile::CFile(bool bEnBuffer)   // 类的构造函数
{
  m_fp=0;
  m_bEnBuffer=bEnBuffer;
  memset(m_filename,0,sizeof(m_filename));
}

// 关闭文件指针
void CFile::Close() 
{
  if (m_fp!=0) fclose(m_fp);  // 关闭文件指针
  m_fp=0;
  memset(m_filename,0,sizeof(m_filename));
}

CFile::~CFile()   // 类的析构函数
{
  if (m_fp!=0) fclose(m_fp);  // 关闭文件指针

  m_fp=0;
}

// 启、禁用缓冲区
void CFile::EnBuffer(bool bEnBuffer)
{
  m_bEnBuffer=bEnBuffer;
}

// 打开文件，参数与fopen相同，打开成功true，失败返回false          
bool CFile::Open(const char *filename,const char *openmode)
{
  Close();

  if ( (m_fp=fopen(filename,openmode)) == 0 ) return false;

  memset(m_filename,0,sizeof(m_filename));

  strncpy(m_filename,filename,300);

  return true;
}

// 调用fprintf向文件写入数据
void CFile::Fprintf(const char *fmt, ... )
{
  if ( m_fp == 0 ) return;

  va_list arg;

  va_start( arg, fmt );
  vfprintf( m_fp, fmt, arg );
  va_end( arg );

  if ( m_bEnBuffer == false ) fflush(m_fp);
}

// 调用fgets从文件中读取一行
bool CFile::Fgets(char *strBuffer,const int ReadSize)
{
  if ( m_fp == 0 ) return;

  memset(strBuffer,0,ReadSize);

  if (fgets(strBuffer,ReadSize,m_fp) == 0) return false;

  return true;
}

