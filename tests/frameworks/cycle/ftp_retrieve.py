# Simple FTP read
# Szymon Gutaj

import sys
import time
import ftplib
import os

host = '192.168.255.69'
port = 21
exit_code = 1

if len(sys.argv) != 3:
    print 'ERROR: FTP: retrieve: invalid arguments count'
    sys.exit(exit_code)

path_remote = sys.argv[1]
path_local = sys.argv[2]

try:
    print 'INFO: FTP: retrieve: ' + path_remote + ' -> ' + path_local

    ftp = ftplib.FTP()

    ftp.connect(host, port, 20)
    ftp.login(user='swlar', passwd='swlar')

    ftp.retrbinary('RETR ' + path_remote, open(path_local, 'wb').write)

    exit_code = 0
    print 'OK: FTP: retrieve: fine'

except ftplib.all_errors:
    print 'ERROR: FTP: retrieve: failed'

ftp.close()
sys.exit(exit_code)