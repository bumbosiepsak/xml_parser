# Simple rebooting via telnet
# Szymon Gutaj

import sys
import time
import ftplib
import os

host = '192.168.255.69'
port = 21
exit_code = 1

if len(sys.argv) != 3:
    print 'ERROR: FTP: store: invalid arguments count'
    sys.exit(exit_code)

path_local = sys.argv[1]
path_remote = sys.argv[2]

if not os.path.exists(path_local):
    print 'ERROR: FTP: store: invalid argument 1 (local path doesn\'t exist: ' + path_local + ')'
    sys.exit(exit_code)

try:
    print 'INFO: FTP: store: ' + path_local + ' -> ' + path_remote

    ftp = ftplib.FTP()

    ftp.connect(host, port, 20)
    ftp.login(user='swlar', passwd='swlar')

    ftp.storbinary('STOR ' + path_remote, open(path_local, 'rb'))

    exit_code = 0
    print 'OK: FTP: store: fine'

except ftplib.all_errors:
    print 'ERROR: FTP: store: failed'

ftp.close()
sys.exit(exit_code)