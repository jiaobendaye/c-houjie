/* 
 *  此程序演示容器存放整数
 *  作者：豫让 日期：20190525
*/
#include <stdio.h> 
#include <vector>      // vector需要的头文件
#include <algorithm>   // sort函数需要的头文件

int main () 
{ 
  int height=0;             // 存放从键盘输入的超女身高
  std::vector<int> vheight; // 存放超女身高的容器

  while (true)
  {
    printf("请输入超女身高（0-结束输入）：");
    scanf("%d",&height);         // 接受键盘输入的数据
    if (height==0) break;        // 0-结束输入
    vheight.push_back(height);   // 把数据追加入容器
  }

  for (int ii=0;ii<vheight.size();ii++) // 显示排序前容器中的记录
  { 
    printf("vheight[%d]=%d\n",ii,vheight[ii]);
  }

  sort(vheight.begin(),vheight.end());  // 容器中的记录排序

  for (int ii=0;ii<vheight.size();ii++) // 显示排序后容器中的记录
  { 
    printf("vheight[%d]=%d\n",ii,vheight[ii]);
  }

  // vheight.clear();  // 清空容器
}



