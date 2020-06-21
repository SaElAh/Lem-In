# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/01 20:06:49 by sel-ahma          #+#    #+#              #
#    Updated: 2019/12/01 20:06:52 by sel-ahma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import os
import re
import sys
import time

nb_exec = 4
final = []
tmp_time = []
option = ''

os.system('clear')

if len(sys.argv) == 2 or len(sys.argv) == 3:
    if sys.argv[1] == '--help' or sys.argv[1] == '-h':
        print('Usage: python3 script.py -[generator option] [nb_executions]\nOptions available for the generator:\n-b or --big\n-bs or --big-superposition\n\
-fo or --flow-one\n-ft or --flow-ten\n-fth or --flow-thousand\n[nb_executions] (default = 10)')
        exit(1)
    elif sys.argv[1] == '-b' or sys.argv[1] == '--big':
        option = '--big'
    elif sys.argv[1] == '-bs' or sys.argv[1] == '--big-superposition':
        option = '--big-superposition'
    elif sys.argv[1] == '-fo' or sys.argv[1] == '--flow-one':
        option = '--flow-one'
    elif sys.argv[1] == '-ft' or sys.argv[1] == '--flow-ten':
        option = '--flow-ten'
    elif sys.argv[1] == '-fth' or sys.argv[1] == '--flow-thousand':
        option = '--flow-thousand'
    if len(sys.argv) == 3:
        while True:
            try:
                tmp = int(sys.argv[2])
            except ValueError:
                break
            else:
                if tmp > 0:
                    nb_exec = tmp
                else:
                    nb_exec = 1
                break

else:
    print('--help or -h for Usage')
    exit(1)

if os.path.isfile('./lem-in'):
    pass
else:
    print('Binary source "lem-in" missing... Please wait for the compilation')
    time.sleep(1)
    os.system('Make re')
    if os.path.isfile('./lem-in') == False:
        print('"./lem-in" could not be found !')
        exit(1)

time.sleep(1)

for ite in range(nb_exec):
    cmd = './generator ' + option + ' > file_to_parse'
    os.system(cmd)
   
    cmd = '(/usr/bin/time ./lem-in < file_to_parse > result) &>time_file' + '; tail -n 1 file_to_parse >> result'
    print('Please wait... Still {0:3} execution(s) of the program'.format(nb_exec - ite))
    os.system(cmd)

    count = len(open('result').readlines())
    cpt = 0
    tab = []
    i = []
    with open('result') as fp:
        for line in fp:
            cpt += 1
            if cpt == count - 1 or cpt == count:
                tab.append(line)
    
    for line in tab:
        i.append(int(re.search(r'\d+', line).group()))
    i.append(i[0] - i[1])
    final.append(i)

    with open('time_file') as fp:
        for line in fp:
            tmp_time.append((re.findall(r'[+-]? *(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][+-]?\d+)?', line)))
    time.sleep(0.5)

time.sleep(1)
os.system('clear')

sum_diff = 0
min_diff = 500
max_diff = -500
time_sum_diff = 0
time_min_diff = 100
time_max_diff = -100


reset = '\u001b[0m'
green = '\u001b[32;1m'
red = '\u001b[31m'
yellow = '\u001b[33;1m'
bright_red = '\u001b[31;1m'

print ('\n\n----------------------------------------------------------------------------')
print ('Number of turns | Number of turns | Difference |   Time user  |  Time user  |')
print ('required        | executed        |            |              |    + sys    |')
print ('----------------------------------------------------------------------------')
for cpt, res in enumerate(final):
    if float(tmp_time[cpt][1]) <= 1:
        color = green
    elif float(tmp_time[cpt][1]) <= 3:
        color = yellow
    elif float(tmp_time[cpt][1]) <= 6:
        color = bright_red
    else :
        color = red
    
    if res[2] < 0:
        print('{0:15} | {1:15} | \033[1;95m{2:10}\033[0;0m |{5}{3}{6} |{5}{4} {6}|' 
                .format(res[0], res[1], res[2], tmp_time[cpt][1], tmp_time[cpt][0], color, reset))
    elif res[2] >= 0 and res[2] <= 3:
        print('{0:15} | {1:15} | \033[1;32m{2:10}\033[0;0m |{5}{3}{6} |{5}{4} {6}|'
                .format(res[0], res[1], res[2], tmp_time[cpt][1], tmp_time[cpt][0], color, reset))
    elif res[2] <= 9:
        print('{0:15} | {1:15} | \033[1;31m{2:10}\033[0;0m |{5}{3}{6} |{5}{4} {6}|' 
                .format(res[0], res[1], res[2], tmp_time[cpt][1], tmp_time[cpt][0], color, reset))
    elif res[2] >= 10:
        print('{0:15} | {1:15} | \033[1;91m{2:10}\033[0;0m |{5}{3}{6} |{5}{4} {6}|' 
                .format(res[0], res[1], res[2], tmp_time[cpt][1], tmp_time[cpt][0], color, reset))
    sum_diff += res[2]
    min_diff = res[2] if min_diff > res[2] else min_diff
    max_diff = res[2] if max_diff < res[2] else max_diff
    time_sum_diff += float(tmp_time[cpt][1])
    time_min_diff = float(tmp_time[cpt][1]) if time_min_diff > float(tmp_time[cpt][1]) else time_min_diff
    time_max_diff = float(tmp_time[cpt][1]) if time_max_diff < float(tmp_time[cpt][1]) else time_max_diff
    

print ('----------------------------------------------------------------------------')
print ('\n\u001b[46;1mAverage nb turns difference = {0:43.2}\u001b[0m' .format(float(sum_diff / nb_exec)))
print ('\u001b[46;1mMaximum nb turns difference = {0:43}\u001b[0m' .format(max_diff))
print ('\u001b[46;1mMinimum nb turns difference = {0:43}\u001b[0m' .format(min_diff))
print ('\n\u001b[44;1mAvg time performance        = {0:44.2}\u001b[0m' .format(time_sum_diff / nb_exec))
print ('\u001b[44;1mBest time performance       =  {0:43}\u001b[0m' .format(time_min_diff))
print ('\u001b[44;1mWorse time performance      =  {0:43}\u001b[0m' .format(time_max_diff))

os.system('rm result time_file file_to_parse')
