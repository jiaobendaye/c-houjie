#include "_public.h"

pthread_t pthid1,pthid2;

// 第一个线程的主函数
void *pth1_main(void *arg);

// 第二个线程的主函数
void *pth2_main(void *arg);

int ii=10;

int main()
{
  // 忽略全部的信号
  for (int ii=0;ii<50;ii++) signal(ii,SIG_IGN);
  
  // 创建线程一
  if ( pthread_create(&pthid1,NULL,pth1_main,(void*)3) != 0)
  {
    printf("pthread_create pthid1 failed.\n"); return -1;
  }
  
  // 创建线程二
  if ( pthread_create(&pthid2,NULL,pth2_main,(void*)4) != 0)
  {
    printf("pthread_create pthid2 failed.\n"); return -1;
  }

  printf("111\n");
  pthread_join(pthid1,NULL);
  printf("222\n");
  pthread_join(pthid2,NULL);
  printf("333\n");
  
  return 0;
}

// 第一个线程的主函数
void *pth1_main(void *arg)
{
  long jj = (long)arg;
  printf("1这是第一个线程，jj=%ld\n",jj);

  printf("2这是第一个线程，ii=%d\n",ii);
  ii=20;
  //sleep(10);
  printf("3这是第一个线程，ii=%d\n",ii);

  //pthread_exit(NULL);
  exit(0);
}

// 第二个线程的主函数
void *pth2_main(void *arg)
{
  long jj = (long)arg;
  printf("1这是第二个线程，jj=%ld\n",jj);

  printf("2这是第二个线程，ii=%d\n",ii);
  sleep(20);
  printf("3这是第二个线程，ii=%d\n",ii);

  pthread_exit(NULL);
}

