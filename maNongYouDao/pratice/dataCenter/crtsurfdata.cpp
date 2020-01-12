#include "_public.h"

using namespace std;
//站点参数
//安徽,58015,砀山,34.27,116.2,44.2
struct st_stcode
{
	char provname[21]; //省名称
	char obtid[11];    //站点编号
	char cityname[31]; //城市名
	double lat;		   //纬度
	double lon;		   //经度
	double height;	   //高度
};
vector<struct st_stcode> vstcode; //存放站点参数的容器

//观测数据结构
struct st_surfdata
{
	char obtid[11];    //站点编号
	char ddatetime[21];  //数据时间: yyyy-mm-dd hh24:mi:ss
	int t;			   //气温 0.1 C
	int p;			   //气压
	int u;			   //相对湿度 0-100
	int wd;			   //风向 0-360
	int wf;			   //风速 0.1m/s 
	int r;			   //降雨量  0.1mm
	int vis;		   //能见度 0.1m
};
//存放观测数据的容器
vector<struct st_surfdata> vsurfdata;

//从站点参数文件加载带vstcode 容器中
bool LoadSTCode(const char *stcodefilename);

//生成随机的数据存入vsurfdata容器中
void CrtSurfData();

//把vsurfdata容器中的数据保存到文件
bool CrtSurfFile(const char *outpath);

//捕获退出信号
void EXIT(int sig);

CLogFile logfile;
int main(int argc, char *argv[])
{

	if(argc!=4)
	{
		printf("\n本程序用于生成全国气象站点观测分钟数据.\n");
		printf("bin/crtsurfdata 站点参数　数据文件存放目录 日志文件名\n");
		printf("例如　bin/crtsurfdata zhandian.ini data/ftp/surfdata data/log/crtsurfdata.log\n");
		return -1;
	}
	//关闭所有的信号和输入输出, 不会printf到屏幕
	void CloseIOAndSignal();
	//处理退出信号
	signal(SIGINT,EXIT);
	signal(SIGTERM,EXIT);

	if(logfile.Open(argv[3], "a+")==false)
	{
		printf("打开日志文件%s失败\n",argv[3]); return -1;
	}
//	for (int ii=0; ii<100000; ii++)
//	{
//		logfile.Write("这是第%d条日志\n",ii+1);
//	}

	while(1)
	{
		//加载数据到容器中
		if(LoadSTCode(argv[1]) == false) return -1;
		logfile.Write("加载参数文件(%s)成功\n",argv[1]);

		CrtSurfData();//创建观测数据，存放到vsurfdata容器中
		//把vsurfdata容器中的数据保存到文件
		if(CrtSurfFile(argv[2])==false) return -1;
		sleep(60);
	}

	return 0;
}
//从站点参数文件加载带vstcode 容器中
bool LoadSTCode(const char *stcodefilename)
{
	CCmdStr CmdStr;
	struct st_stcode stcode;
	memset(&stcode,0,sizeof(struct st_stcode));	

	CFile File;
	if(File.Open(stcodefilename,"r") ==false)
	{
		logfile.Write("open(%s) false",stcodefilename); return false;
	}
	
	char strbuffer[101];
	while(true)
	{
		if(File.Fgets(strbuffer,100)==false) break;
		//printf("strbuffer=%s",strbuffer);
		
		CmdStr.SplitToCmd(strbuffer,",",true);
		CmdStr.GetValue(0, stcode.provname);
		CmdStr.GetValue(1, stcode.obtid);
		CmdStr.GetValue(2, stcode.cityname);
		CmdStr.GetValue(3,&stcode.lat);
		CmdStr.GetValue(4,&stcode.lon);
		CmdStr.GetValue(5,&stcode.height);

		//printf("provname=%s,obtid=%s,cityname=%s,lat=%.2lf,lon=%2lf,height=%.2f\n",stcode.provname,stcode.obtid,stcode.cityname,stcode.lat,stcode.lon,stcode.height);
		vstcode.push_back(stcode);		

	}

	return true;
}
void CrtSurfData()
{
	srand(time(0));	//random seed

	struct st_surfdata stsurfdata;
	for (int ii=0;ii<vstcode.size();ii++)
	{
		char strLocalTime[21];
		LocalTime(strLocalTime,"yyyy-mm-dd hh24:mi");
		strcat(strLocalTime, ":00");

		memset(&stsurfdata,0,sizeof(struct st_surfdata));
		STRCPY(stsurfdata.obtid,11,vstcode[ii].obtid);
		STRCPY(stsurfdata.ddatetime, 20, strLocalTime);//数据采集时间为当前时间
		stsurfdata.t=rand()%351;
		stsurfdata.p=rand()%264+10000;
		stsurfdata.u=rand()%100+1;
		stsurfdata.wd=rand()%360;
		stsurfdata.wf=rand()%150;
		stsurfdata.r=rand()%16;
		stsurfdata.vis=rand()%5000+10000;
		
		vsurfdata.push_back(stsurfdata);
	}
}
//把vsurfdata容器中的数据保存到文件
bool CrtSurfFile(const char *outpath)
{
	CFile File;

	char strLocaltime[21];
	LocalTime(strLocaltime,"yyyymmddhhmiss");

	char strFileName[301];
	SNPRINTF(strFileName,300,"%s/SURF_ZH_%s_%d.txt",outpath,strLocaltime,getpid());

	if(File.OpenForRename(strFileName,"w")==false)
	{
		printf("open(%s) failed)",strFileName);return false;
	}

	for(int ii=0; ii<vsurfdata.size();ii++)
	{
		File.Fprintf("%s,%s,%.1lf,%.1lf,%d,%d,%.1lf,%.1lf,%.1lf\n",\
				vsurfdata[ii].obtid,vsurfdata[ii].ddatetime,\
				vsurfdata[ii].t/10.0,vsurfdata[ii].p/10.0,vsurfdata[ii].u,\
				vsurfdata[ii].wd,vsurfdata[ii].wf/10.0,vsurfdata[ii].r/1.00,\
				vsurfdata[ii].vis/10.0);
	}

	File.CloseAndRename();

	logfile.Write("生成文件(%s), 数据时间＝%s, 记录数%d.\n",strFileName, vsurfdata[0].ddatetime, vsurfdata.size());
	logfile.Write("\n");

	return true;
}
void EXIT(int sig)
{
	logfile.Write("程序退出，sig=%d\n", sig);

	exit(0);
}
