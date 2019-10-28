/* 
 *  此程序演示时间操作的mktime库函数
 *  作者：豫让 日期：20190601
*/
#include <stdio.h>
#include <time.h>
#include <string.h>

int main(int argc,char *argv[])
{
  /*
    2019年06月20日10时16分27秒的整数表示是1560996987
  */
  struct tm sttm;  
  memset(&sttm,0,sizeof(sttm));

//2019-07-15 09:46:40

  sttm.tm_year=2019-1900; // 注意，要减1900
  sttm.tm_mon=7-1;        // 注意，要减1
  sttm.tm_mday=15;
  sttm.tm_hour=9;
  sttm.tm_min=46;
  sttm.tm_sec=40;
  sttm.tm_isdst = 0;
  printf("%lu\n",mktime(&sttm));
}

