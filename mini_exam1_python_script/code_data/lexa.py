#!/usr/bin/python

import os
import subprocess

a = input()

if a == "?":
    print("-- If you want to recode all text files in a directory and subdirectories, enter : ./lab_21.sh directory encoding. The encoding type must be written in uppercase --")
    exit()
#if (os.path.isdir(a) != True):
#    print(a + "is not directory")
#   exit()

b = input()

cod_comm = 'iconv -l | grep "^{recipient}//"'
cod_comm = cod_comm.replace('{recipient}', b)

print("cod_comm: " + cod_comm)

coding_1 = subprocess.run(cod_comm, shell=True, stdout=subprocess.PIPE, encoding='utf-8')
coding = coding_1.stdout

print("coding: " + coding)

print("len(list(coding)): " + str(len(list(coding))))

if len(list(coding)) == 0:
    print(b + " is not valid encoding ")
    exit()
