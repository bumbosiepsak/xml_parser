# MSVC compiler wrapper for make-compatible dependency file generation

import fileinput
import os
import string
import sys
import subprocess

target = sys.argv[len(sys.argv) - 1]

cmdline = [sys.argv[1], target] + sys.argv[3:len(sys.argv) - 2]

p = subprocess.Popen(cmdline, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)

o = open(sys.argv[len(sys.argv) - 2],'w')

firstline = 1

for line in p.stdout:
    if line.startswith('Note: including file:'):
        line = line[21:].strip()
        line = line.replace('\\', '/')
        line = line.replace(' ', '\ ')
        o.write(line + '\\\n')
    elif firstline == 1:
        firstline = 0
        o.write(sys.argv[len(sys.argv) - 2] + ':\\\n')
    else:
        sys.stdout.write(line)

o.close()

ret = p.wait()
if ret != 0:
    sys.exit(1)
else:
    sys.exit(0)
