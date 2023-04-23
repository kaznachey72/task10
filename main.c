#include "crc32.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

static void exit_failure(char *msg, int fd) 
{
    perror(msg);
    if (fd >= 0) {
        close(fd);
    }
    exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        printf("USAGE: %s <input file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        exit_failure("open: ошибка доступа к файлу", -1);
    }

    struct stat st;
    if(fstat(fd, &st) == -1) {
        exit_failure("указан не регулярный файл", fd);
    }
    if ((st.st_mode & S_IFMT) != S_IFREG) {
        exit_failure("fstat: ошибка получения свойств файла", fd);
    }

    uint8_t *addr = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED) {
        exit_failure("mmap: ошибка отображения файла в память", fd);
    }
    
    close(fd);

    {
        uint32_t crc = crc32(0, addr, st.st_size);
        printf("%x  %s\n", crc, argv[1]);
    }

    munmap(addr, st.st_size);

    return EXIT_SUCCESS;
}
