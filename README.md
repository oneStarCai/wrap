# wraper
  include compliler, linker, run time wraper

## compiling
$ gcc -DCOMPILETIME -c mymalloc.c 

$ gcc -I. -o intc int.c mymalloc.o

$ ./intc


## linking
$ gcc -DLINKTIME -c mymallo.c

$ gcc -c int.c

$ gcc -Wl, --wrap,malloc -Wl,--wrap,free -o intl int.o mymalloc.o

$ ./intl


## running
$ gcc -DRUNTIME -shared -fpic -o mymalloc.so mymalloc.c -ldl

$ gcc -o intr int.c

$ LD_PRELOAD="./mymalloc.so" ./intr


