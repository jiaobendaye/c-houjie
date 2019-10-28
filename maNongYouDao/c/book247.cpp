/* 
 *  此程序演示socket通信客户端
 *  作者：豫让 日期：20190601
*/
#include "_public.h"

// TCP客户端类
class CTcpClient
{
public:
  int m_sockfd;

  CTcpClient();

  // 向服务器发起连接，serverip-服务端ip，port通信端口
  bool ConnectToServer(const char *serverip,const int port);
  // 向对端发送报文
  int  Send(const void *buf,const int buflen);
  // 接收对端的报文
  int  Recv(void *buf,const int buflen);

 ~CTcpClient();
};

int main()
{
  CTcpClient TcpClient;

  // 向服务器发起连接请求
  if (TcpClient.ConnectToServer("192.168.149.129",5000)==false)
  { printf("连接服务器失败，程序退出。\n"); return -1; }

  char strbuffer[1024];
  
  // 与服务端通信，发送一个报文后等待回复，然后再发下一个报文。
  for (int ii=0;ii<5;ii++)
  {
    memset(strbuffer,0,sizeof(strbuffer));
    sprintf(strbuffer,"这是第%d个报文。",ii);
    if (TcpClient.Send(strbuffer,strlen(strbuffer))<=0) break;
    printf("发送：%s\n",strbuffer);
    
    memset(strbuffer,0,sizeof(strbuffer));
    if (TcpClient.Recv(strbuffer,sizeof(strbuffer))<=0) break;
    printf("接收：%s\n",strbuffer);

    sleep(1);
  }
}

CTcpClient::CTcpClient()
{
  m_sockfd=0;  // 构造函数初始化m_sockfd
}

CTcpClient::~CTcpClient()
{
  if (m_sockfd!=0) close(m_sockfd);  // 析构函数关闭m_sockfd
}

// 向服务器发起连接，serverip-服务端ip，port通信端口
bool CTcpClient::ConnectToServer(const char *serverip,const int port)
{
  // 如果已连接，先关闭
  if (m_sockfd!=0) { close(m_sockfd); m_sockfd=0; }

  m_sockfd = socket(AF_INET,SOCK_STREAM,0); // 创建客户端的socket

  struct hostent* h; // ip地址信息的数据结构
  if ( (h=gethostbyname(serverip))==0 ) 
  { close(m_sockfd); m_sockfd=0; return false; }

  // 把服务器的地址和端口转换为数据结构
  struct sockaddr_in servaddr;
  memset(&servaddr,0,sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port); 
  memcpy(&servaddr.sin_addr,h->h_addr,h->h_length);

  // 向服务器发起连接请求
  if (connect(m_sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))!=0)
  { close(m_sockfd); m_sockfd=0; return false; }

  return true;
}

int CTcpClient::Send(const void *buf,const int buflen)
{
  return send(m_sockfd,buf,buflen,0);
}

int CTcpClient::Recv(void *buf,const int buflen)
{
  return recv(m_sockfd,buf,buflen,0);
}

