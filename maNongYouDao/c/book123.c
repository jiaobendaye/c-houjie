/* 
 *  此程序演示目录操作
 *  作者：豫让 日期：20190601
*/
#include <stdio.h>
#include <dirent.h>

int main(int argc,char *argv[])
{
  DIR *dir;   // 定义目录指针

  // 打开/tmp目录
  if ( (dir=opendir(argv[1])) == 0 ) return -1;

  // 用于存放从目录中读取到的文件和目录信息
  struct dirent *stdinfo;

  while (1)
  {
    // 读取一条记录并显示到屏幕
    if ((stdinfo=readdir(dir)) == 0) break;

    printf("name=%s,type=%d\n",stdinfo->d_name,stdinfo->d_type);
  }

  closedir(dir);   // 关闭目录指针
}


