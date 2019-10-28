/* 
 *  此程序演示目录和文件的存取权限和状态信息
 *  作者：豫让 日期：20190601
*/
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include "_public.h"

// 本程序运行要带一个参数，即文件或目录名
int main(int argc,char *argv[])
{
  if (access(argv[1],F_OK) != 0) 
  {
    printf("文件或目录%s不存在。\n",argv[1]); return -1;
  }

  struct utimbuf stut;
  strtotime("2019-02-01 12:20:35",&stut.actime);
  strtotime("2019-02-01 12:20:35",&stut.modtime);
  
  utime(argv[1],&stut);

  struct stat ststat;
  // 获取文件的状态信息
  if (stat(argv[1],&ststat) != 0) return -1;

  if (S_ISREG(ststat.st_mode)) printf("%s是一个文件。\n",argv[1]);
  if (S_ISDIR(ststat.st_mode)) printf("%s是一个目录。\n",argv[1]);
 
  char strtime[20];
  memset(strtime,0,sizeof(strtime));
  timetostr(ststat.st_mtime,strtime);

  printf("filename=%s,mtime=%s,size=%d\n",argv[1],strtime,ststat.st_size);
}


