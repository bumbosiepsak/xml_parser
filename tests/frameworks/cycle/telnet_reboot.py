# Simple rebooting via telnet
# Szymon Gutaj

import sys
import time
import telnetlib

host = '192.168.255.69'
port = 2323
reboot_timeout = 480
exit_code = 1

try:
    print 'INFO: Telnet: rebooting: connecting'

    tn = telnetlib.Telnet(host, port, reboot_timeout)

    tn.read_until('$')

    command = 'Mcu -r 1 6\n'

    print 'INFO: Telnet: rebooting: ' + command

    tn.write(command)

    exit_code = 0
    print 'OK: Telnet: rebooting: fine'

except:
    print 'ERROR: Telnet: rebooting: failed'

sys.exit(exit_code)