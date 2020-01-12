#include "_public.h"
#include "_ftp.h"

using namespace std;

struct st_arg
{
	char host[51];
	int mode;
	char username[31];
	char password[31];
	char localpath[301];
	char remotepath[301];
	char matchname[301];
	int ptype;
	char remotepathbak[301];
	char listfilename[301];
	char okfilename[301];
} starg;

Cftp ftp;

// 日志文件
CLogFile logfile;

// 本程序的业务流程主函数
bool _ftpgetfile();

vector<struct st_fileinfo> vlistfile,vlistfile1;
vector<struct st_fileinfo> vokfilename,vokfilename1;

// 把nilist方法获取到的list文件加载到vlistfile容器中
bool LoadListFile();
struct st_fileinfo
{
	char filename[301];
	char mtime[21];
};

// 把okfilename文件的内容加载到vokfilename容器中
bool LoadOKFileName();

// 把vlistfile容器中的文件与容器vokfilename中的文件对比，得到两个容器
// 一、在vlistfile中存在，并已经采集成功的文件vokfilename1
// 二、在vlistfile中存在，新文件或需要重新采集的文件vlistfile1
bool CompVector();

// 把vokfilename1容器中的内容先写入okfilename文件中，覆盖之前的旧okfilename文件
bool WriteToOKFileName();

// 如果ptype==1，把采集成功的文件记录追加到okfilename文件中
bool AppendToOKFileName(struct st_fileinfo *stfileinfo);

// 程序退出
void EXIT(int sig);

int main(int argc,char *argv[])
{
	if(argc!=3)
	{
	  printf("\n实现一个公共的功能模块，从ftp服务器上采集文件。\n\n");
	  printf("用法：/home/chenlong/qxidc/bin/ftpgetfile logfilename xmlbuffer\n\n");
	  printf("例如：/home/jiaobendaye/Documents/lab/c++/maNongYouDao/pratice/dataCenter/bin/ftpgetfile /home/jiaobendaye/Documents/lab/c++/maNongYouDao/pratice/dataCenter/data/log/ftp.log \"<host>118.89.50.198:21</host><mode>1</mode><username>test</username><password>test1234TEST</password><localpath>/tmp</localpath><remotepath>/home/test/zym</remotepath><matchname>*.cpp</matchname><ptype>1</ptype><remotepathbak>/home/test/fzh</remotepathbak><listfilename>/tmp/cpp_ftp_test_zym.list</listfilename><okfilename>/tmp/cpp_ftp_test_zym.xml</okfilename>\"\n\n\n");
	  printf("本程序是数据中心的公共功能模块，用于把远程FTP服务器的文件采集到本地目录。\n");
	  printf("logfilename是程序运行的日志文件名。\n");
	  printf("xmlbuffer为文件传输的参数，如下：\n");
	  printf("<host>118.89.50.198:21</host> 远程服务器的IP和端口。\n");
	  //printf("<port>21</port> 远程服务器FTP的端口。\n");
	  printf("<mode>1</mode> 传输模式，1-被动模式，2-主动模式，缺省为被动模式。\n");
	  printf("<username>test</username> 远程服务器FTP的用户。\n");
	  printf("<password>test1234TEST</password> 远程服务器FTP的密码。\n");
	  printf("<localpath>/tmp</localpath> 本地文件存放的目录。\n");
	  printf("<remotepath>/home/test/zym</remotepath> 远程服务器存放文件的目录。\n");
	  printf("<matchname>*.cpp</matchname> 待采集文字匹配的文件名，采用大写匹配，"\
		  "不匹配的文件不会被采集，本字段尽可能设置精确，不允许用*匹配全部的文件。\n");
	  printf("<ptype>3</ptype> 文件采集成功后，远程服务器文件的处理方式：1-什么都不做；2-删除；3-备份，如果为3，还得指定备份的目录。\n");
	  printf("<remotepathbak>/home/test/fzh</remotepathbak> 文件采集成功后，服务器文件的备份目录，此参数只有当ptype=3时才有效。\n");
  	  printf("<listfilename>/tmp/cpp_ftp_test_zym.list</listfilename> 采集前列出服务器文件名的文件。\n");
  	  printf("<okfilename>/tmp/cpp_ftp_test_zym.xml</okfilename> 已采集成功文件名清单。\n");

	  return -1;
	}

	// 关闭全部的信号和输入输出
	void CloseIOAndSignal();

	// 处理程序退出的信号
	signal(SIGINT,EXIT);signal(SIGTERM,EXIT);

	if(logfile.Open(argv[1],"a+")==false)
	{
		printf("打开日志文件失败(%s)！\n",argv[1]);
		return -1;
	}

	memset(&starg,0,sizeof(struct st_arg));
	GetXMLBuffer(argv[2],"host",starg.host);
	GetXMLBuffer(argv[2],"mode",&starg.mode);
	GetXMLBuffer(argv[2],"username",starg.username);
	GetXMLBuffer(argv[2],"password",starg.password);
	GetXMLBuffer(argv[2],"localpath",starg.localpath);
	GetXMLBuffer(argv[2],"remotepath",starg.remotepath);
	GetXMLBuffer(argv[2],"matchname",starg.matchname);
	GetXMLBuffer(argv[2],"ptype",&starg.ptype);
	GetXMLBuffer(argv[2],"remotepathbak",starg.remotepathbak);
	GetXMLBuffer(argv[2],"listfilename",starg.listfilename);
	GetXMLBuffer(argv[2],"okfilename",starg.okfilename);
	if(strcmp(starg.matchname, "*") == 0) {
		logfile.Write("matchname can not be *\n");
		return -1;
	}
	//char okbuffer[301];
	//SNPRINTF(okbuffer, 300, "%s_%s", starg.okfilename, starg.matchname);
	//STRCPY(starg.okfilename, 300, okbuffer);
	//printf("okfilename: %s\n", starg.okfilename);
	
	int mode=1;
	if(mode==0) mode=2;
	if(ftp.login(starg.host,starg.username,starg.password,mode)==false)
	{
		logfile.Write("登录ftp.login(%s,%s,%s) failed.\n",starg.host,starg.username,starg.password);
		return -1;
	}

	logfile.Write("登录ftp.login ok.\n");

	_ftpgetfile();

	return 0;
}

// 程序退出
void EXIT(int sig)
{
	logfile.Write("程序退出，sig=%d\n",sig);
	exit(0);
}

// 本程序的业务流程主函数
bool _ftpgetfile()
{
	// 切换服务器文件所在目录
	if(ftp.chdir(starg.remotepath)==false)
	{
		logfile.Write("服务器目录切换ftp.chdir(%s) failed.\n",starg.remotepath);
		return false;
	}
	logfile.Write("服务器目录切换ftp.chdir(%s) ok.\n",starg.remotepath);

	// 列出服务器目录文件并生成list文件
	if(ftp.nlist(".",starg.listfilename)==false)
	{
		logfile.Write("生成本地list文件ftp.nlist(%s) failed.\n",starg.listfilename);
		return false;
	}
	logfile.Write("生成本地list文件ftp.nlist(%s) ok.\n",starg.listfilename);

	// 把nilist方法获取到的list文件加载到vlistfile容器中
	if(LoadListFile()==false)
	{
		logfile.Write("加载本地list文件LoadListFile() failed.\n");
		return false;
	}
	logfile.Write("加载本地list文件LoadListFile() ok.\n");

	if(starg.ptype==1)
	{
		// <filename>SURF_ZH_20191104225801_2585.txt</filename><mtime>20191104225801</mtime>
		// 加载okfilename文件中的内容到容器vokfilename中
		if(LoadOKFileName()==false)
		{
			logfile.Write("加载本地XML文件LoadOKFileName() failed.\n");
                	return false;
		}
		logfile.Write("加载本地XML文件LoadOKFileName() ok.\n");

		// 把vlistfile容器中的文件与容器vokfilename中的文件对比，得到两个容器
		// 一、在vlistfile中存在，并已经采集成功的文件vokfilename1
		// 二、在vlistfile中存在，新文件或需要重新采集的文件vlistfile1
		logfile.Write("容器比较文件CompVector().\n");
		CompVector();
		//for (int ii=0;ii<vokfilename1.size();ii++){
		//	printf("vokfilename1 %d: %s\n", ii, vokfilename1[ii].filename);
		//}

		// 把vokfilename1容器中的内容先写入okfilename文件中，覆盖之前的旧okfilename文件
		// 更新okfile
	//	if(WriteToOKFileName()==false)
	//	{
	//		logfile.Write("写入XML文件WriteToOKFileName() failed.\n");
    //                    return false;
	//	}
	//	logfile.Write("写入XML文件WriteToOKFileName() ok.\n");

		// 把vlistfile1容器中的内容复制到vlistfile容器中
		vlistfile.clear();
		vlistfile.swap(vlistfile1);
	}

	// 待获取的服务器文件名和本地文件名的绝对路径
	char strremotefilename[301],strlocalfilename[301];

	for(int ii=0;ii<vlistfile.size();ii++)
	{
		SNPRINTF(strremotefilename,300,"%s/%s",starg.remotepath,vlistfile[ii].filename);
		SNPRINTF(strlocalfilename,300,"%s/%s",starg.localpath,vlistfile[ii].filename);

		logfile.Write("获取文件get %s ... ",vlistfile[ii].filename);
		// 获取文件
		if(ftp.get(strremotefilename,strlocalfilename,true)==false)
		{
			logfile.WriteEx("failed.\n");
			return false;
		}
		logfile.WriteEx("ok.\n");

		// 删除服务器文件
		if(starg.ptype==2){ftp.ftpdelete(strremotefilename);}

		// 服务器文件转存到备份目录
		if(starg.ptype==3)
		{
			char strremotefilenamebak[301];
			SNPRINTF(strremotefilenamebak,300,"%s/%s",starg.remotepathbak,vlistfile[ii].filename);
			if(ftp.ftprename(strremotefilename,strremotefilenamebak)==false)
			{
				logfile.Write("服务器文件备份ftp.ftprename(%s) failed.\n",strremotefilename);
				return false;
			}
			logfile.Write("ftp.ftprename(%s) ok.\n",strremotefilename);
		}

		// 如果ptype==1，把采集成功的文件记录追加到okfilename文件中
		if(starg.ptype==1)
		{
			AppendToOKFileName(&vlistfile[ii]);
		}
	}

	return true;
}

// 把nilist方法获取到的list文件加载到vlistfile容器中
bool LoadListFile()
{
	vlistfile.clear();

	CFile File;

	if(File.Open(starg.listfilename,"r")==false)
	{
		logfile.Write("File.Open(%s) failed.\n",starg.listfilename);
		return false;
	}

	struct st_fileinfo strfileinfo;

	while(true)
	{
		memset(&strfileinfo,0,sizeof(struct st_fileinfo));
		if(File.Fgets(strfileinfo.filename,300,true)==false) {
			break;
		}

		if(MatchFileName(strfileinfo.filename,starg.matchname)==false) continue;

		if(starg.ptype==1)
		{
			// 获取对方服务器文件时间
			if(ftp.mtime(strfileinfo.filename)==false)
			{
				logfile.Write("ftp.mtime(%s) failed.\n",strfileinfo.filename);
				return false;
			}

			strcpy(strfileinfo.mtime,ftp.m_mtime);
		}

		vlistfile.push_back(strfileinfo);

		//logfile.Write("本地list文件数据vlistfile filename=%s,mtime=%s\n",strfileinfo.filename,
	}
	return true;
}

// 把okfilename文件的内容加载到vokfilename容器中
bool LoadOKFileName() {
	vokfilename.clear();

	CFile File;

	if (File.Open(starg.okfilename, "r") == false) return true;

	struct st_fileinfo stfileinfo;

	char strbuffer[301];

	while (true) {
		memset(&stfileinfo, 0, sizeof(struct st_fileinfo));
		
		if (File.Fgets(strbuffer, 300, true) == false) break;
		GetXMLBuffer(strbuffer, "filename", stfileinfo.filename, 300);
		GetXMLBuffer(strbuffer, "mtime", stfileinfo.mtime, 20);

		vokfilename.push_back(stfileinfo);
	}
	return true;
}


// 把vlistfile容器中的文件与容器vokfilename中的文件对比，得到两个容器
// 一、在vlistfile中存在，并已经采集成功的文件vokfilename1
// 二、在vlistfile中存在，新文件或需要重新采集的文件vlistfile1
bool CompVector() {
	vokfilename1.clear(); vlistfile1.clear();
	
	for (int ii=0;ii<vlistfile.size();ii++) {
		int jj;
		for (jj=0;jj<vokfilename.size();jj++)
		{
			if (strcmp(vlistfile[ii].filename, vokfilename[jj].filename)==0 ) {
				if (strcmp(vlistfile[ii].mtime, vokfilename[jj].mtime)==0)
				{
				vokfilename1.push_back(vlistfile[ii]);
				break;
				}

			}

		}
		if (jj == vokfilename.size()) {
			vlistfile1.push_back(vlistfile[ii]);
		}
	}
	return true;
}

// 把vokfilename1容器中的内容先写入okfilename文件中，覆盖之前的旧okfilename文件
bool WriteToOKFileName() {
	CFile File;
	if (File.Open(starg.okfilename, "w") == false) {
		logfile.Write("File.Open(%s) falied\n", starg.okfilename);
		return false;
	}
	
	for  (int ii=0;ii<vokfilename1.size();ii++) {
		File.Fprintf("<filename>%s</filename><mtime>%s</mtime>\n",vokfilename1[ii].filename, vokfilename[ii].mtime);

	}
	File.Close();
	return true;
}

// 如果ptype==1，把采集成功的文件记录追加到okfilename文件中
bool AppendToOKFileName(struct st_fileinfo *stfileinfo) {
	CFile File;
	if (File.Open(starg.okfilename, "a") == false) {
		logfile.Write("File.Open(%s) falied\n", starg.okfilename);
		return false;
	}

	File.Fprintf("<filename>%s</filename><mtime>%s</mtime>\n",stfileinfo->filename, stfileinfo->mtime);
	return true;
}
