/*
   此程序用于演示把自定义函数定义在程序外部的程序文件中
   作者：豫让   日期：20190601
*/

#include "_public.h"  // 包含自定义函数声明的头文件

// 用于比较两个整数的大小，函数返回较大者
int max(const int ii1,const int ii2)   // max函数定义
{
  if (ii1>ii2) return ii1;

  return ii2;
}

// 用于比较两个整数的大小，函数返回较小者
int min(const int ii1,const int ii2)   // min函数定义
{
  if (ii1<ii2) return ii1;

  return ii2;
}

// 把字符的'0'、'1'、'2'、'3'、'4'、'5'、'6'、'7'、'8'、'9'转换为整数的0、1、2、3、4、5、6、7、8、9。
// 参数chr为字符，返回值为数字，失败返回-1。
int ctoi(const char chr)
{
  if ( (chr<'0') || (chr>'9') ) return -1;

  return chr-'0';
}

// 求x的y次幂，函数返回值为x的y次幂。
long  POW(const int x,const int y)
{
  int ii=0;

  long result=1;
 
  for (ii=1;ii<=y;ii++)
  {
    result=result*x;
  }
  
  return result;
}



char *STRCPY(char* dest,const size_t destlen,const char* src)
{
  memset(dest,0,destlen); 

  if (strlen(src)>destlen-1) strncpy(dest,src,destlen-1);
  else strcpy(dest,src);

  return dest;
}

char *STRNCPY(char* dest,const size_t destlen,const char* src,size_t n)
{
  memset(dest,0,destlen); 

  if (n>destlen-1) strncpy(dest,src,destlen-1);
  else strncpy(dest,src,n);

  return dest;
}

char *STRCAT(char* dest,const size_t destlen,const char* src)
{
  memset(dest+strlen(dest),0,destlen-strlen(dest)); 
  
  int left=destlen-1-strlen(dest);

  int len=0;

  if (strlen(src)>left) len=left;
  else len=strlen(src);
  
  strncat(dest,src,len);

  return dest;
}

char *STRNCAT (char* dest,const size_t destlen,const char* src,size_t n)
{
  memset(dest+strlen(dest),0,destlen-strlen(dest)); 
  
  int left=destlen-1-strlen(dest);

  int len=0;

  if (n>left) len=left;
  else len=n;
  
  strncat(dest,src,len);

  return dest;
}

// 解析xml的函数
// in_XMLBuffer，XML格式的字符串，如下：
// <name>西施</name><age>18</age><sc>火辣</sc><yz>漂亮</yz>
// in_FieldName，字段的标签名。
// out_Value，获取内容存放的变量的指针。
// 返回值，0-成功，-1-失败。
int  GetXMLBuffer(const char *in_XMLBuffer,const char *in_FieldName,char *out_Value)
{
  char bfieldname[51],efieldname[51];

  memset(bfieldname,0,sizeof(bfieldname));
  memset(efieldname,0,sizeof(efieldname));

  sprintf(bfieldname,"<%s>",in_FieldName);
  sprintf(efieldname,"</%s>",in_FieldName);

  char *start,*end;
  start=end=0;

  start=(char *)strstr(in_XMLBuffer,bfieldname);
  end=(char *)strstr(in_XMLBuffer,efieldname);

  if ( (start==0) || (end==0) ) return -1;

  strncpy(out_Value,start+strlen(bfieldname),end-start-strlen(bfieldname));
  
  return 0;
}


// 把整数的时间转换为字符串格式的时间，格式如："2019-02-08 12:05:08"，如果转换成功函数返回0，失败返回-1，函数的声明如下：
int timetostr(const time_t ti,char *strtime)
{
  struct tm *sttm; 

  if ( (sttm=localtime(&ti))==0 ) return -1;

  sprintf(strtime,"%d-%02d-%02d %02d:%02d:%02d",\
          sttm->tm_year+1900,sttm->tm_mon+1,sttm->tm_mday,sttm->tm_hour,sttm->tm_min,sttm->tm_sec);
  
  return 0;
}

// 把字符串格式的时间转换为整数的时间，函数的声明如下：
int strtotime(const char *strtime,time_t *ti)
{
  char strtmp[11];

  //"2019-02-08 12:05:08"
  struct tm sttm; 

  memset(strtmp,0,sizeof(strtmp));
  strncpy(strtmp,strtime,4);
  sttm.tm_year=atoi(strtmp)-1900;
  
  memset(strtmp,0,sizeof(strtmp));
  strncpy(strtmp,strtime+5,2);
  sttm.tm_mon=atoi(strtmp)-1;
  
  memset(strtmp,0,sizeof(strtmp));
  strncpy(strtmp,strtime+8,2);
  sttm.tm_mday=atoi(strtmp);
  
  memset(strtmp,0,sizeof(strtmp));
  strncpy(strtmp,strtime+11,2);
  sttm.tm_hour=atoi(strtmp);
  
  memset(strtmp,0,sizeof(strtmp));
  strncpy(strtmp,strtime+14,2);
  sttm.tm_min=atoi(strtmp);
  
  memset(strtmp,0,sizeof(strtmp));
  strncpy(strtmp,strtime+17,2);
  sttm.tm_sec=atoi(strtmp);

  *ti=mktime(&sttm);

  return *ti;
}
