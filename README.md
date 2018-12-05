# wraper
  include compliler, linker, run time wraper

## compiling
[caihanwu: ~/workspace/cpp/test/wrap]$ gcc -DCOMPILETIME -c mymalloc.c 

[caihanwu: ~/workspace/cpp/test/wrap]$ gcc -I. -o intc int.c mymalloc.o

[caihanwu: ~/workspace/cpp/test/wrap]$ ./intc


## linking
[caihanwu: ~/workspace/cpp/test/wrap]$ gcc -DLINKTIME -c mymallo.c

[caihanwu: ~/workspace/cpp/test/wrap]$ gcc -c int.c

[caihanwu: ~/workspace/cpp/test/wrap]$ gcc -Wl, --wrap,malloc -Wl,--wrap,free -o intl int.o mymalloc.o

[caihanwu: ~/workspace/cpp/test/wrap]$ ./intl


## running
[caihanwu: ~/workspace/cpp/test/wrap]$ gcc -DRUNTIME -shared -fpic -o mymalloc.so mymalloc.c -ldl

[caihanwu: ~/workspace/cpp/test/wrap]$ gcc -o intr int.c

[caihanwu: ~/workspace/cpp/test/wrap]$ LD_PRELOAD="./mymalloc.so" ./intr


