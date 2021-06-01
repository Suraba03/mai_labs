#!/bin/bash

#read -p "Enter a number in bytes: " n_bytes
read -p "тестовая директория: " direc

n_bytes=$1
prefix=$2

if [[ $1 == ? && $# -eq 1 ]] # помощь при вводе пользователем знака ?
then
    echo "Чтобы удалить файлы с определенным префиксом (названием) до определенного общего объема файлов в директории, нужно ввести следующую команду: ./test1.sh число_в_байтах префикс. 'Число_в_байтах' должно содержать лишь цифры десятичного алфавита, 'префикс' вводится как обычное название файла"
    exit 1
fi

if [[ $# -ne 2 ]] # проверка на количество введённых аргументов
then
    if [[ $# -gt 2 ]]
    then
        echo "Вы ввели больше двух аргументов. Пожалуйста, введите 2 аргумента"
        exit 1
    fi
    if [[ $# -lt 2 ]]
    then
        echo "Вы ввели меньше двух аргументов. Пожалуйста, введите 2 аргумента"
        exit 1
    fi
fi

total_size=$(find ~/$direc/ -type f -name "$prefix.*" -exec du -cb {} + | grep total$ | awk '{ print $1 }')
max_file=$(find ~/$direc/ -type f -name "$prefix.*" -exec du -cb {} + | sort -n -r | head -n2 | awk 'NR == 2 { print $2 }')

echo "изначальный объем всех файлов $total_size"
#echo $max_file

while [[ $total_size -ge $n_bytes ]]
do
    echo "файл $max_file удален"
    rm $max_file
    max_file=$(find ~/$direc/ -type f -name "$prefix.*" -exec du -cb {} + | sort -n -r | head -n2 | awk 'NR == 2 { print $2 }')
    total_size=$(find ~/$direc/ -type f -name "$prefix.*" -exec du -cb {} + | grep total$ | awk '{ print $1 }')
done

echo "конечный объем всех файлов $total_size"





































# подать на вход префикс и число
# создать папки mkdir -p dir{000..100}
# создать в папках файлы touch dir{000..100}/file_a
# заполнить файл рандомным содержимым cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w 8 | head -n 6 > file_a
# подсчитать суммарный размер файлов в папке в байтах: find ~/for_lab21/ -type f -name '*' -exec du -cb {} + | grep total$
