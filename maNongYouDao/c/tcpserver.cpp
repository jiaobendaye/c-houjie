/* 
 *  此程序演示socket通信服务端
 *  作者：豫让 日期：20190601
*/
#include <stdio.h>
#include <string.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

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
  int serverfd = socket(AF_INET,SOCK_STREAM,0);  // 创建服务端用于监听的socket

  // 把服务端用于通信的地址和端口绑定到socket上
  struct sockaddr_in servaddr;    // 服务端地址信息的数据结构
  memset(&servaddr,0,sizeof(servaddr));
  servaddr.sin_family = AF_INET;  // 协议族，在socket编程中只能是AF_INET
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);  // 本主机的任意ip地址
  servaddr.sin_port = htons(5001);  // 绑定通信端口
  if (bind(serverfd,(struct sockaddr *)&servaddr,sizeof(servaddr)) != 0 )
  { perror("bind"); close(serverfd); return -1; }

  // 把socket设置为监听模式
  if (listen(serverfd,5) != 0 ) { perror("listen"); close(serverfd); return -1; }

  // 接受客户端的连接。
  int clientfd=accept(serverfd,0,0);

  // 与客户端通信，接收客户端发过来的报文后，回复ok。
  char buffer[1024];
  while (1)
  {
    memset(buffer,0,sizeof(buffer));
    if (recv(clientfd,buffer,sizeof(buffer),0)<=0) break;
    printf("收到：%s\n",buffer);

    if (strcmp(buffer,"bye")==0) break;

    memset(buffer,0,sizeof(buffer));
    printf("请回复：");
    scanf("%s",buffer);
    if (send(clientfd,buffer,strlen(buffer),0)<=0) break;
  }

  close(serverfd); close(clientfd);  // 关闭socket
}


