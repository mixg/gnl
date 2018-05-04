rm -f a.out

gcc -Wall -Wextra -Werror libft/libft.a get_next_line.c mymain.c

./a.out gnl7_1.txt
echo "FILE CONTENT: 7_1"
cat gnl7_1.txt
./a.out gnl7_2.txt
echo "FILE CONTENT: 7_2"
cat gnl7_2.txt
./a.out gnl7_3.txt
echo "FILE CONTENT: 7_3"
cat gnl7_3.txt
./a.out gnl8_1.txt
echo "FILE CONTENT: 8_1"
cat gnl8_1.txt
./a.out gnl8_2.txt
echo "FILE CONTENT: 8_2"
cat gnl8_2.txt
./a.out gnl8_3.txt
echo "FILE CONTENT: 8_3"
cat gnl8_3.txt
