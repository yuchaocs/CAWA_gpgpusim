#!/usr/bin/python
import re
def find_pattern(contents, pattern):
    cycle_str = re.compile(pattern).findall(contents)
    cycles = [int(re.compile('[\d]+').findall(x)[0]) for x in cycle_str]
    return sum(cycles)

import sys
for i in range(len(sys.argv)-1):
    f=open(sys.argv[i+1])
    contents=f.read()
    f.close()
    print find_pattern(contents, 'gpu_sim_cycle = [\d]+')
