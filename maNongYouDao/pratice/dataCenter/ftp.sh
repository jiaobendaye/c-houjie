#下载文件
ftp -n <<EOF
open 118.89.50.198
user test test1234TEST
binary
cd /home/test/fzh
lcd /home/jiaobendaye/Documents/lab/c++/maNongYouDao/pratice/dataCenter/data/ftp/dow
prompt off
mget *
bye
EOF
echo "download from ftp sucessfully"

