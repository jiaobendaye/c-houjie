/* 
 *  此程序演示socket通讯客户端
 *  作者：豫让 日期：20190601
*/
#include "_public.h"

int main()
{
  int sockfd = socket(AF_INET,SOCK_STREAM,0); // 创建客户端的socket

  struct hostent* h; // ip地址信息的数据结构
  if ( (h = gethostbyname("192.168.149.129")) == 0 )
  { perror("gethostbyname"); close(sockfd); return -1; }

  // 把服务器的地址和端口转换为数据结构
  struct sockaddr_in servaddr;
  memset(&servaddr,0,sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(5000); 
  memcpy(&servaddr.sin_addr,h->h_addr,h->h_length);

  // 向服务器发起连接请求
  if (connect(sockfd, (struct sockaddr *)&servaddr,sizeof(servaddr)) != 0)
  { perror("connect"); close(sockfd); return -1; }

  char strbuffer[1024];
  
  // 与服务端通讯，发送一个报文后等待回复，然后再发下一个报文。
  for (int ii=0;ii<5;ii++)
  {
    memset(strbuffer,0,sizeof(strbuffer));
    sprintf(strbuffer,"这是第%d个报文。",ii);
    if (send(sockfd,strbuffer,strlen(strbuffer),0)<=0) break;
    printf("发送：%s\n",strbuffer);
    
    memset(strbuffer,0,sizeof(strbuffer));
    if (recv(sockfd,strbuffer,sizeof(strbuffer),0)<=0) break;
    printf("接收：%s\n",strbuffer);
  }

  close(sockfd);
}
