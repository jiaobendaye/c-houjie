/* 
 *  此程序演示目录及子目录操作
 *  作者：豫让 日期：20190601
*/
#include <stdio.h>
#include <dirent.h>

// 列出目录及子目录下的文件
int ReadDir(const char *strpathname);

int main(int argc,char *argv[])
{
  // 列出目录及子目录下的文件
  ReadDir(argv[1]);
}

// 列出目录及子目录下的文件
int ReadDir(const char *strpathname)
{
  DIR *dir;   // 定义目录指针
  char strchdpath[256];  // 子目录的全路径

  if ( (dir=opendir(strpathname)) == 0 ) return -1; // 打开目录

  struct dirent *stdinfo; // 用于存放从目录读取到的文件和目录信息

  while (1)
  {
    if ((stdinfo=readdir(dir)) == 0) break;   // 读取一记录

    if (strncmp(stdinfo->d_name,".",1)==0) continue;  // 以.开始的文件不要

    if (stdinfo->d_type==8)    // 如果是文件，显示出来
      printf("name=%s/%s\n",strpathname,stdinfo->d_name);

    if (stdinfo->d_type==4)   // 如果是目录，再调用一次ReadDir
    {
      sprintf(strchdpath,"%s/%s",strpathname,stdinfo->d_name);
      ReadDir(strchdpath);
    }
  }

  closedir(dir);   // 关闭目录指针
}



