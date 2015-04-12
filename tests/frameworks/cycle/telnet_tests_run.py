# Simple unit tests running via telnet
# Szymon Gutaj

import sys
import time
import telnetlib

unit_tests_command = 'uoam_tests'

host = '192.168.255.69'
port = 2323
reboot_timeout = 480
exit_code = 1

if len(sys.argv) != 2:
    print 'ERROR: Telnet: running: invalid arguments count'
    sys.exit(exit_code)

tests_dump = sys.argv[1]

try:
    print 'INFO: Telnet: running: connecting'

    tn = telnetlib.Telnet(host, port, reboot_timeout)

    tn.read_until('$')

    command = unit_tests_command + ' > ' + tests_dump + '\n'

    print 'INFO: Telnet: running: ' + command

    tn.write(command)

    tn.read_until('$')

    tn.write('exit\n')

    exit_code = 0
    print 'OK: Telnet: running: fine'

except:
    print 'ERROR: Telnet: running: failed'

tn.close()
sys.exit(exit_code)