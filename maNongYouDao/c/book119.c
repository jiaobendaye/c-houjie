/* 
 *  此程序演示文件的复制功能
 *  作者：豫让 日期：20190601
*/
#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
  if (argc != 3)
  {
    printf("\n这是一个文件复制程序，类似Linux系统的cp命令。\n");
    printf("用法：./book119 srcfilename dstfilename\n");
    printf("例如：./book119 /oracle/c/book1.c /tmp/book1.c\n");
    printf("srcfilename 源文件名。\n");
    printf("dstfilename 目标文件名。\n\n");
    return -1;
  }

  FILE *srcfp,*dstfp;     // 源文件和目标文件的文件指针

  srcfp=dstfp=0;

  int ii;

  printf("ii=%d\n",ii);

  char name[30];

  printf("name=%s\n",name);

  // 以只读的方式打开源文件，模式是rb
  if ( (srcfp=fopen(argv[1],"rb")) == 0) 
  { printf("fopen(%s) failed.\n",argv[1]); return -1; }

  // 以只写的方式打开目标文件，模式是wb
  if ( (dstfp=fopen(argv[2],"wb")) == 0) 
  { printf("fopen(%s) failed.\n",argv[2]); fclose(srcfp); return -1; }

  int  nread=0;         // 每次读取到的内容的字节数
  char strbuf[500];     // 存放每次从文件读取到的内容的缓冲区，注意，这不是个字符串。

  while (1)
  { // 从源文件中读取数据，并写入目标文件
    memset(strbuf,0,sizeof(strbuf));
    if ( (nread=fread(strbuf,1,500,srcfp)) == 0) break;
    fwrite(strbuf,1,nread,dstfp);
  }

  fclose(srcfp); fclose(dstfp); // 关闭文件

  printf("文件复制成功。\n");

  return 0;
}


