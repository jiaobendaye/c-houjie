#ifndef _PUBLIC_H
#define _PUBLIC_H 1

#include <stdarg.h>
#include <stdio.h>
#include <cstring>
#include <sys/types.h>          /* See NOTES */
#include <sys/stat.h>
#include <unistd.h>
#include <utime.h>
#include <netdb.h>
#include <stdlib.h>
#include <cstdlib>
#include <signal.h>
#include <string>

#include <vector>


//返回较大的值
int max(const int ii1, const int ii2);

//返回较小的值
int min(const int ii1, const int ii2);

// 用某文件或目录的全路径中的目录创建目录，以及该目录下的各级子目录
// pathorfilename 目录名或文件名
// bisfilename true-pathorfilename是文件名，否则是目录名
bool MKDIR(const char *pathorfilename,bool bisfilename=true);

// 判断字符串中的负号和圆点是否合法
bool JudgeSignDOT(const char *strSrc,const char *strBZ);

// 从一个字符串中提取数字，bWithSign==true表示包括负号，bWithDOT==true表示包括圆点
void PickNumber(const char *strSrc,char *strDst,const bool bWithSign,const bool bWithDOT);

// 把字符串格式的时间转换为time_t
// stime为输入的时间，格式不限，但一定要包括yyyymmddhh24miss
time_t UTCTime(const char *stime);

// 更改文件的修改时间属性，mtime指定了时间，格式不限，只要包括了yyyy,mm,dd,hh24,mi,ss即可。
int UTime(const char *filename,const char *mtime);

// 获取文件的大小，返回字节数
int FileSize(const char *in_FullFileName);

// 调用fopen函数打开文件，如果文件名中包含的目录不存在，就创建目录
FILE *FOPEN(const char *filename,const char *mode);

// STRCPY、STRNCPY、STRCAT、STRNCAT四个函数，弥补库函数的缺陷
// 以后可以用这四个函数取代strcpy、strncpy、strcat、strncat
// 函数的第二个参数是第一个参数dest有效长度，即占用内存的字节数-1。
// 该系列函数解决三个问题：1）变量初始化；2）内存溢出；3）修复strncpy的缺陷。
char *STRCPY(char* dest,const size_t destlen,const char* src);
char *STRNCPY(char* dest,const size_t destlen,const char* src,size_t n);
char *STRCAT(char* dest,const size_t destlen,const char* src);
char *STRNCAT(char* dest,const size_t destlen,const char* src,size_t n);
int SNPRINTF(char *str, const size_t size,const char *fmt, ...);

//文件操作类声明
class CFile
{
private:
	FILE *m_fp;
	bool m_bEnBuffer;
	char m_filename[301];
	char m_filenametmp[301];
public:
	CFile();

	~CFile();
	bool Open(const char *filename, const char *openmode,bool bEnBuffer=true);

	bool OpenForRename(const char *filename, const char *openmode,bool bEnBuffer=true);

	void Fprintf(const char *fmt, ...);

	// 调用fgets从文件中读取一行，bDelCRT=true删除换行符，false不删除
	bool Fgets(char *strBuffer,const int ReadSize, bool bDelCRT=false);

	bool CloseAndRename();
	void Close();
};
//拆分字符串的类
//如num~!~name~!~address,分隔符为~!~
class CCmdStr
{
public:
	std::vector<std::string> m_vCmdStr; //存放拆分后的内容
	CCmdStr();

	void SplitToCmd(const std::string in_string, const  char *in_sep,const bool bdeletespace=true);

	int CmdCount();//返回容器的大小

	//获取字段的值，取每个字段的值inum从０开始
	bool GetValue(const int inum,char *in_return);
	bool GetValue(const int inum,char *in_return,const int in_len);
	bool GetValue(const int inum,int *in_return);
	bool GetValue(const int inum,long *in_return);
	bool GetValue(const int inum,double *in_return);
	~CCmdStr();
};
//删除左or右的字符
void DeleteRChar(char *in_string, const char in_char);
void DeleteLChar(char *in_string, const char in_char);
void DeleteLRChar(char *in_string, const char in_char);

///////////////////////////////////////////////////////////////////////////////////////////////////
/*
  取操作系统的时间
  out_stime是输出结果
  in_interval是偏移常量，单位是秒
  返回的格式由fmt决定，fmt目前的取值如下，如果需要，可以增加：
  yyyy-mm-dd hh:mi:ss，此格式是缺省格式
  yyyymmddhhmiss
  yyyy-mm-dd
  yyyymmdd
  hh:mi:ss
  hhmiss
  hh:mi
  hhmi
  hh
  mi
*/
void LocalTime(char *out_stime,const char *in_fmt=0,const int in_interval=0);


/*
  把一个字符串表格的时间加上一个偏移量，得到偏移后的时间
  in_stime是传入的时间，任意格式，但是一定要包括yyyymmddhh24miss，是否有分隔符没有关系。
  把yyyy-mm-dd hh24:mi:ss偏移in_interval秒
  传出的格式由fmt决定，fmt目前的取值如下，如果需要，可以增加：
  yyyy-mm-dd hh24:mi:ss（此格式是缺省格式）
  yyyymmddhh24miss
  yyyymmddhh24miss
  yyyy-mm-dd
  yyyymmdd
  hh24:mi:ss
  hh24miss
  hh24:mi
  hh24mi
  返回值：0-成功，-1-失败。
*/
int AddTime(const char *in_stime,char *out_stime,const int in_interval,const char *in_fmt=0);

///////////////////////////////////////////////////////////////////////////////////////////////////
// 以下是日志文件操作类

// 日志文件操作类
class CLogFile
{
public:
  FILE   *m_tracefp;           // 日志文件指针
  char    m_filename[301];     // 日志文件全名
  char    m_openmode[11];      // 日志文件的打开方式
  bool    m_bBackup;           // 日志文件超出100M，是否自动备份
  bool    m_bEnBuffer;         // 写入日志时，是否启用操作系统的缓冲机制

  CLogFile();

  // filename日志文件名
  // openmode打开文件的方式，操作日志文件的权限,同打开文件函数(fopen)使用方法一致，一般采用"a+"
  // bBackup，true-备份，false-不备份，在多进程的服务程序中，如果多个进行共用一个日志文件，bBackup必须为false
  // bEnBuffer:true-启用缓冲区，false-不启用缓冲区，如果启用缓冲区，那么写进日志文件中的内容不会立即写入文件
  bool Open(const char *in_filename,const char *in_openmode,bool bBackup=true,bool bEnBuffer=false);

  // 如果日志文件大于100M，就备份它
  // 备份后的文件会在源文件名后加上日期时间
  bool BackupLogFile();

  // 写日志文件,它是个可变参数的方法,同printf函数。
  // Write()方法会写入时间，WriteEx()方法不写时间。
  bool Write(const char *fmt,...);
  bool WriteEx(const char *fmt,...);

  // 关闭日志文件
  void Close();

  ~CLogFile();
};
//关闭所有的信号和输入输出
void CloseIOAndSignal();

// 以下是XML格式字符串的相关操作函数和类

// 操作XMLBuffer的函数
// in_XMLBuffer，XML格式的字符串，如下：
// <filename>/tmp/readme.txt</filename><mtime>2018-01-01 12:20:35</mtime><size>10241</size>
// in_FieldName，字段的标签名
// out_Value，获取内容存放的变量的指针
bool GetXMLBuffer(const char *in_XMLBuffer,const char *in_FieldName,bool   *out_Value);
bool GetXMLBuffer(const char *in_XMLBuffer,const char *in_FieldName,int    *out_Value);
bool GetXMLBuffer(const char *in_XMLBuffer,const char *in_FieldName,unsigned int *out_Value);
bool GetXMLBuffer(const char *in_XMLBuffer,const char *in_FieldName,long   *out_Value);
bool GetXMLBuffer(const char *in_XMLBuffer,const char *in_FieldName,unsigned long *out_Value);
bool GetXMLBuffer(const char *in_XMLBuffer,const char *in_FieldName,double *out_Value);
bool GetXMLBuffer(const char *in_XMLBuffer,const char *in_FieldName,char   *out_Value,const int in_StrLen=0);

// 判断文件名是否匹配in_MatchStr指定的规则
// in_FileName文件名
// in_MatchStr规则表达式，如"*.txt,*.xml"，中间用逗号分隔
bool MatchFileName(const std::string in_FileName,const std::string in_MatchStr);

// 把小写转换成大写，忽略不是字母的字符
void ToUpper(char *str);
void ToUpper(std::string &str);

// 把大写转换成小写，忽略不是字母的字符
void ToLower(char *str);
void ToLower(std::string &str);

#endif
