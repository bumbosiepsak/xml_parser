# Simple flashing via telnet
# Szymon Gutaj

import sys
import time
import telnetlib

host = '192.168.255.69'
port = 2323
reboot_timeout = 480
exit_code = 1

if len(sys.argv) != 3:
    print 'ERROR: Telnet: flashing: invalid arguments count'
    sys.exit(exit_code)

path_remote_flash = sys.argv[1]
path_remote = sys.argv[2]

try:
    print 'INFO: Telnet: flashing: connecting'

    tn = telnetlib.Telnet(host, port, reboot_timeout)

    tn.read_until('$')

    command = 'flash -u ' + path_remote_flash + ' ' + path_remote + '\n'

    print 'INFO: Telnet: flashing: ' + command

    tn.write(command)

    result = tn.read_until('$')

    if result.find('Update succeeded!'):
        print 'OK: Telnet: flashing: fine'
        exit_code = 0
    else:
        print 'ERROR: Telnet: flashing: failed (FRM FLASH error)'

except:
    print 'ERROR: Telnet: flashing: failed (connection error)'

tn.close()
sys.exit(exit_code)
