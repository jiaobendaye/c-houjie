#ifndef _FTP_H
#define _FTP_H

#include "_public.h"
#include "ftplib.h"

class Cftp
{
public:
	//ftp句柄
	netbuf *m_ftpconn;

	//文件的大小
	unsigned int m_size;

	//文件的时间modify time
	char m_mtime[21];

	Cftp();
	~Cftp();
	
	//存放login()方法登录失败的原因
	bool m_connectfailed;
	bool m_loginfailed;
	bool m_optionfailed;

	void initdata();

	//登录服务器
	//in_host 服务器地址和端口，用":"分隔，如＂192.168.1.1:21"
	//in_username ftp用户名
	//in_password ftp密码
	//in_mode 传输模式，FTPLIB_PASSIVE是被动，FTPLIB_PORT是主动
	bool login(const char *in_host,const char *in_username,const char *in_password,const int in_mode=FTPLIB_PASSIVE);

	//注销
	bool logout();

	//获取ftp服务器上文件的时间
	bool mtime(const char *in_remotefilename);

	//获取ftp服务器上文件的大小
	bool size(const char *in_remotefilename);

	//向服务端发送site命令
	bool site(const char *in_command);

	//改变ftp远程目录
	bool chdir(const char *in_remotedir);

	//创建ftp远程目录
	bool mkdir(const char *in_remotedir);

	//删除ftp远程目录
	bool rmdir(const char *in_remotedir);

	//发送list命令列出ftp服务器目录中的文件，结果保存到本地文件中
	//如果是列出当前目录，in_remotedir用"*", "", "."都行
	bool nlist(const char *in_remotedir, const char *out_listfilename);

	//发送dir命令列出ftp服务器目录中的文件，结果保存到本地文件中
	bool dir(const char *in_remotedir, const char *out_listfilename);


	//从ftp服务器上获取文件
	//in_remotefilename 待获取文件名
	//in_localfilename 本地文件名，可以不同
	//bCheckMTime 文件传输完成后，是否核对本地和远程文件的修改时间，保证文件的完整
	//注意，在传输过程中，使用了临时文件名".tmp"
	bool get(const char *in_remotefilename,const char *in_localfilename,const bool bCheckMTime=true);

	//从ftp服务器上发送文件
	//in_remotefilename 待获取文件名
	//in_localfilename 本地文件名，可以不同
	//bCheckSize 文件传输完成后，是否核对本地和远程文件的大小，保证文件的完整
	//注意，在传输过程中，使用了临时文件名".tmp"
	bool put(const char *in_localfilename,const char *in_remotefilename,const bool bCheckSize=true);

	//删除ftp服务器上的文件
	bool ftpdelete(const char *in_remotefilename);

	//删除ftp服务器上的文件
	bool ftprename(const char *in_srcremotefilename,const char *in_dstremotefilename);

	//return a pointer to the last response received
	char *response();
};

#endif
