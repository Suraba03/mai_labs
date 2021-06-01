#!/usr/bin/python

import os
import subprocess

# Functions for replacing to prefix and direc variables

def replace_total_size():
    total_size_comm_temp = "find ~/{recipient1}/ -type f -name '{recipient2}.*' -exec du -cb {} + | grep total$ | awk '{ print $1 }'"
    ts_comm = total_size_comm_temp.replace('{recipient1}', direc)
    return ts_comm.replace('{recipient2}', prefix)

def replace_max_file():
    max_file_comm_temp = "find ~/{recipient1}/ -type f -name '{recipient2}.*' -exec du -cb {} + | sort -n -r | head -n2 | awk 'NR == 2 { print $2 }' | less"
    mf_comm = max_file_comm_temp.replace('{recipient1}', direc)
    return mf_comm.replace('{recipient2}', prefix)

# Functions for returning outputs of terminal commands

def total_size_output():
    total_size1 = subprocess.run(ts_comm, shell=True, stdout=subprocess.PIPE, encoding='utf-8')
    return total_size1.stdout

def max_file_output():
    max_file1 = subprocess.run(mf_comm, shell = True, stdout = subprocess.PIPE, encoding='utf-8')
    max_file = max_file1.stdout
    return max_file[0:-1]

# Help for user

if input("Enter ? if you don't know what to do, else click enter: ") == '?':
    print("To delete files with a certain prefix (name) to a certain total number of files in the directory, enter the following command: python script22.py, then follow the instructions in the terminal. 'number_in_bytes' must contain only the digits of the decimal alphabet,' prefix ' is entered as a normal file name")
    exit()

# Data entry

n_bytes = int(input("Enter a number in bytes: "))
prefix = input("Enter the prefix: ")
direc = input("Enter the test directory: ")

# Replacing

ts_comm = replace_total_size()
mf_comm = replace_max_file()

# Getting output

total_size = total_size_output()
max_file = max_file_output()


print("изначальный объем всех файлов: " + str(total_size))

while int(total_size) >= n_bytes:

    print("файл " + str(max_file) + " удален")

    # removing max file

    os.remove(max_file)

    # Replacing

    ts_comm = replace_total_size()
    mf_comm = replace_max_file()

    # Getting output

    total_size = total_size_output()
    max_file = max_file_output()

print("конечный объем всех файлов:" + str(total_size))















#total_size1 = subprocess.Popen("find ~/test1/ -type f -name 'file_a.*' -exec du -cb {} + | grep total$ | awk '{ print $1 }'", shell = True, stdout = subprocess.PIPE)
#total_size = total_size1.communicate()[0]
#max_file1 = subprocess.Popen("find ~/test1/ -type f -name 'file_a.*' -exec du -cb {} + | sort -n -r | head -n2 | awk 'NR == 2 { print $2 }'", shell = True, stdout = subprocess.PIPE)
#max_file = max_file1.communicate()[0]
