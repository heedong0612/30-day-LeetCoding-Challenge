find . | grep ".cpp" | cut -d"." -f2 | cut -d"_" -f1 |
while read i;
do
    # echo ${i:1}_Jun.py
    touch ${i:1}_Jun.py
done