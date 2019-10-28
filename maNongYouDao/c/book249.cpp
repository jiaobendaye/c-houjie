/* 
 *  此程序演示多进程的socket通信服务端
 *  作者：豫让 日期：20190601
*/
#include "_public.h"

class CTcpServer
{
public:
  int m_listenfd;   // 服务端用于监听的socket
  int m_clientfd;   // 客户端连上来的socket

  CTcpServer();

  bool InitServer(int port);  // 初始化服务端

  bool Accept();  // 等待客户端的连接

  // 向对端发送报文
  int  Send(const void *buf,const int buflen);
  // 接收对端的报文
  int  Recv(void *buf,const int buflen);

  void CloseClient();    // 关闭客户端的socket
  void CloseListen();    // 关闭用于监听的socket

 ~CTcpServer();
};

CTcpServer TcpServer;

// SIGINT和SIGTERM的处理函数
void EXIT(int sig)
{
  printf("程序退出，信号值=%d\n",sig);

  TcpServer.~CTcpServer();  // 手动调用析构函数，释放资源

  exit(0);
}

int main()
{
  // 忽略全部的信号
  for (int ii=0;ii<50;ii++) signal(ii,SIG_IGN);

  // 设置SIGINT和SIGTERM的处理函数
  signal(SIGINT,EXIT); signal(SIGTERM,EXIT);

  if (TcpServer.InitServer(5000)==false)
  { printf("服务端初始化失败，程序退出。\n"); return -1; }

  while (1)
  {
    if (TcpServer.Accept() == false) continue;

    if (fork()>0) { TcpServer.CloseClient(); continue; }

    TcpServer.CloseListen();

    printf("客户端已连接。\n");

    // 与客户端通信，接收客户端发过来的报文后，回复ok。
    char strbuffer[1024];

    while (1)
    {
      memset(strbuffer,0,sizeof(strbuffer));
      if (TcpServer.Recv(strbuffer,sizeof(strbuffer))<=0) break;
      printf("接收：%s\n",strbuffer);

      strcpy(strbuffer,"ok");
      if (TcpServer.Send(strbuffer,strlen(strbuffer))<=0) break;
      printf("发送：%s\n",strbuffer);
    }

    printf("客户端已断开连接。\n");

    return 0; // 子进程退出
  }
}

CTcpServer::CTcpServer()
{
  // 构造函数初始化socket
  m_listenfd=m_clientfd=0;
}

CTcpServer::~CTcpServer()
{
  if (m_listenfd!=0) close(m_listenfd);  // 析构函数关闭socket
  if (m_clientfd!=0) close(m_clientfd);  // 析构函数关闭socket
}

// 初始化服务端的socket，port为通信端口
bool CTcpServer::InitServer(int port)
{
  if (m_listenfd!=0) { close(m_listenfd); m_listenfd=0; }

  m_listenfd = socket(AF_INET,SOCK_STREAM,0);  // 创建服务端的socket

  // 把服务端用于通信的地址和端口绑定到socket上
  struct sockaddr_in servaddr;    // 服务端地址信息的数据结构
  memset(&servaddr,0,sizeof(servaddr));
  servaddr.sin_family = AF_INET;  // 协议族，在socket编程中只能是AF_INET
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);  // 本主机的任意ip地址
  servaddr.sin_port = htons(port);  // 绑定通信端口
  if (bind(m_listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr)) != 0 )
  { close(m_listenfd); m_listenfd=0; return false; }

  // 把socket设置为监听模式
  if (listen(m_listenfd,5) != 0 ) { close(m_listenfd); m_listenfd=0; return false; }

  return true;
}

bool CTcpServer::Accept()
{
  if ( (m_clientfd=accept(m_listenfd,0,0)) <= 0) return false;

  return true;
}

int CTcpServer::Send(const void *buf,const int buflen)
{
  return send(m_clientfd,buf,buflen,0);
}

int CTcpServer::Recv(void *buf,const int buflen)
{
  return recv(m_clientfd,buf,buflen,0);
}

void CTcpServer::CloseClient()    // 关闭客户端的socket
{
  if (m_clientfd!=0) { close(m_clientfd); m_clientfd=0; }
}
void CTcpServer::CloseListen()    // 关闭用于监听的socket
{
  if (m_listenfd!=0) { close(m_listenfd); m_listenfd=0; }
}

