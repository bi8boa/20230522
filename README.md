第一个终端

gcc publicpipe_create.c -o 1

gcc public_mkfifo.c -o 2

gcc transform.c -o 6

第二个终端

gcc p1_read.c -o 4

gcc p1_login.c -o 3

gcc p1_data.c -o 7

第三个终端

gcc p2_read.c -o 5

第四个终端

gcc all.c -o all   (8)

gcc quit.c -o quit  (10)

第五个终端

gcc sendall.c -o sendall   (9)

gcc sendquit.c -o sendquit  (11)
