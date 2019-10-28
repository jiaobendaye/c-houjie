/* 
 *  此程序演示文本文件的写入
 *  作者：豫让 日期：20190601
*/
#include <stdio.h>

int main()
{
  printf("Hello world.\n");
  fprintf(stdout,"Hello world.\n");
return 0;
  int   ii=0;
  FILE *fp=0;     // 定义文件指针变量fp

  // 以只写的方式打开文件/tmp/test1.txt
  if ( (fp=fopen("/tmp/test1.txt","w")) == 0) 
  {
    printf("fopen(/tmp/test1.txt) failed.\n"); return -1;
  }

  for (ii=0;ii<100;ii++) // 往文件中写入5行
  {
    printf("ii=%d\n",ii);
    fprintf(fp,"这是第%d条数数据。\n",ii+1);
    fflush(fp);
    sleep(1);
  }
  
  // 关闭文件
  fclose(fp);
}


