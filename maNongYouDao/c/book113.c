/* 
 *  此程序演示文本文件的读取
 *  作者：豫让 日期：20190601
*/
#include <stdio.h>
#include <string.h>

int main()
{
  FILE *fp=0;        // 定义文件指针变量fp
  char strbuf[301];  // 存放从文件中读取到的一行的内容

  // 以只读的方式打开文件/oracle/c/book1.c
  if ( (fp=fopen("/oracle/c/book1.c","rt")) == 0) 
  {
    printf("fopen(/oracle/c/book1.c) failed.\n"); return -1;
  }

  fseek(fp,-200,2); 

  printf("%d\n",ftell(fp));

  // 逐行读取文件的内容，输出到屏幕
  while (1)
  {
    memset(strbuf,0,sizeof(strbuf));
    if (fgets(strbuf,301,fp)==0) break;
    printf("%d:%s",ftell(fp),strbuf);
  }
  
  // 关闭文件
  fclose(fp);
}


