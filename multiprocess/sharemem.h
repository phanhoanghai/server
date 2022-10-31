#ifndef SHAREMEM_H
#define SHAREMEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>

class ShareMem
{
private:
    ShareMem();

public:
    static ShareMem* getInstance();

public:
    bool initShareMem();
};

#endif // SHAREMEM_H
