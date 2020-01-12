#include "_ftp.h"

int main(int argc, char *argv[]) {
	Cftp ftp;

	//登录	
	if (ftp.login("118.89.50.198:21","test","test1234TEST",FTPLIB_PASSIVE)==false) {
		printf("ftp.login() failed.\n"); return -1;
	}
	printf("login()\n");

	//改变本地目录
	chdir("/tmp");

	//进入ftp服务器上文件存放的目录
	if (ftp.chdir("/home/test/zym") == false) {
		printf("ftp.chdir() failed.\n"); return -1;
	}

	//获取对方的文件列表，
	if (ftp.nlist("*.cpp", "/tmp/ftp.list") == false) {
		printf("ftp.nlist() failed.\n"); return -1;
	}

	CFile File;

	File.Open("/tmp/ftp.list", "r");

	char strFilename[101];

	//按行读取文件的内容，并get到本地
	while(true) {
		//从文件读取一行
		memset(strFilename, 0, sizeof(strFilename));
		if (File.Fgets(strFilename,100) == false) break;
		//去除换行
		strFilename[strlen(strFilename)-1]=0;

		printf("get %s...", strFilename);
		//从远程获取文件
		if (ftp.get(strFilename, strFilename)==false) {
			printf("ftp.get(%s) failed.\n", strFilename); break;
		}
		
		printf("ok.\n");
	}
	File.Close();
}
