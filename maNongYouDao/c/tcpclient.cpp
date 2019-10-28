/* 
 *  此程序演示socket通信客户端
 *  作者：豫让 日期：20190601
*/
#include <stdio.h>
#include <string.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

struct st_girl
{
  char name[50];     // 姓名
  int  age;          // 年龄
  int  height;       // 身高，单位：厘米cm
  char sc[30];       // 身材，火辣；普通；飞机场。
  char yz[30];       // 颜值，漂亮；一般；歪瓜裂枣。
};

int main()
{
  int sockfd = socket(AF_INET,SOCK_STREAM,0); // 创建客户端的socket

  struct hostent* h; // ip地址信息的数据结构
  if ( (h = gethostbyname("192.168.149.135")) == 0 )
  { close(sockfd); return -1; }

  // 把服务器的地址和端口转换为数据结构
  struct sockaddr_in servaddr;
  memset(&servaddr,0,sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(5001); 
  memcpy(&servaddr.sin_addr,h->h_addr,h->h_length);

  // 向服务器发起连接请求
  if (connect(sockfd, (struct sockaddr *)&servaddr,sizeof(servaddr)) != 0)
  { perror("connect"); close(sockfd); return -1; }

  char buffer[1024];

  // 与服务端通信，发送一个报文后等待回复，然后再发下一个报文。
  for (int ii=0;ii<10;ii++)
  {
    memset(buffer,0,sizeof(buffer));
    printf("请发言：");
    scanf("%s",buffer);
    if (send(sockfd,buffer,strlen(buffer),0)<=0) break;

    
    memset(buffer,0,sizeof(buffer));
    if (recv(sockfd,buffer,sizeof(buffer),0)<=0) break;
    printf("接收：%s\n",buffer);
  }

  close(sockfd);
}

