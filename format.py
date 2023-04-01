"""usage

 python3 format.py hmw/hmw5.c

"""
import sys
import os

res = ''
filename = 'hmw5.c'
if len(sys.argv) > 1:
    filename = sys.argv[1] 
filepath = os.path.join(os.getcwd(), filename)

with open(filename, 'r') as f:
    for line in f.readlines():
        sp = line.split(' ', 1)
        if sp[0].isdigit() or (len(sp[0]) > 1 and sp[0][0].isdigit()):
            if len(sp) > 1 and not sp[1][0].isdigit():
                res += sp[1]
        else:
            res += line
res = res.replace("”", "\"").replace('p rin tf', 'printf').replace('exi t', 'exit').replace('k i l l', 'kill')
with open(filename, 'w') as f:
    f.write(res)