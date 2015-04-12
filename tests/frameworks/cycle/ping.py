# Simple ping
# Szymon Gutaj

import sys
import time
import os
import re

host = '192.168.255.69'

def ping(address):
    print 'INFO: ping: ' + address

    ip_text = '    Packets: Sent = 1, Received = '

    ip_file = os.popen("ping "+address+" -n 1","r")
    lines = ip_file.readlines()

    test = re.search(ip_text, lines[6])

    if (test):
        if (lines[6][len(ip_text):len(ip_text)+1:1] == '1'):
            ip_file.close()
            return 1
        else:
            ip_file.close()
            return 0

while(ping(host) == 0):
    pass

print 'OK: ping: connected'
sys.exit(0)