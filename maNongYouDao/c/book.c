#include <stdio.h>
#include <string.h>
#include "_public.h"

// 存放不重复的结果
int arii[52];

// 检查irand是否在arii数组中，0-存在，1-不存在
int checkin(int irand);

// 把irand放入arii数组中
void putin(int irand);

int main()
{
  srand(time(0));
  
  int irand;

  // 洗牌
  while (1)
  {
    irand=rand()%52+1;  // 取一个数

    // 检查已获取的随机数是否在数组中
    if (checkin(irand)==0) continue;

    // 把irand放入数组中
    putin(irand);

    printf("%d ",irand);

    if (arii[51]!=0) break;
  }

  printf("\n");

  // 发牌
  int man1[13],man2[13],man3[13],man4[13];

  int ii=0;
  int jj=0;
  for (ii=0;ii<52;ii=ii+4)
  {
    man1[jj]=arii[ii];
    man2[jj]=arii[ii+1];
    man3[jj]=arii[ii+2];
    man4[jj]=arii[ii+3];
    jj++;
  }  
 
  // 第1个人的牌
  for (ii=0;ii<13;ii++)
  {
    printf("%d ",man1[ii]);
  }
  printf("\n");

  // 第2个人的牌
  for (ii=0;ii<13;ii++)
  {
    printf("%d ",man2[ii]);
  }
  printf("\n");

  // 第3个人的牌
  for (ii=0;ii<13;ii++)
  {
    printf("%d ",man3[ii]);
  }
  printf("\n");

  // 第4个人的牌
  for (ii=0;ii<13;ii++)
  {
    printf("%d ",man4[ii]);
  }
  printf("\n");

}

// 检查irand是否在arii数组中，0-存在，1-不存在
int checkin(int irand)
{
  int ii=0;
  for (ii=0;ii<52;ii++)
  {
    if (irand==arii[ii]) return 0;
  }  

  return 1;
}

// 把irand放入arii数组中
void putin(int irand)
{
  int ii=0;
  for (ii=0;ii<52;ii++)
  {
    if (arii[ii]==0) { arii[ii]=irand; return; }
  }  
}


