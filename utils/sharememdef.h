#ifndef SHAREMEMDEF_H
#define SHAREMEMDEF_H

#include <memory.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

#define SHM_PATH "/data"
#define SHM_PERMISSIONS 0660  // read and write access for user and group
#define SHM_SIZE 12
#define INT_LEN 12

#endif // SHAREMEMDEF_H
