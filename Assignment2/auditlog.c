#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    int fd, openFlags;
    mode_t fileParams;
    ssize_t numRead;
    char buf[BUF_SIZE];

    if (argc < 2) {
        printf("Usage:\n");
        printf("./auditlog --add \"message\"\n");
        printf("./auditlog --view\n");
        exit(-1);
    }

    // ---------- ADD ----------
    if (strcmp(argv[1], "--add") == 0) {

        if (argc != 3) {
            printf("Usage: ./auditlog --add \"message\"\n");
            exit(-1);
        }

        openFlags = O_CREAT | O_WRONLY | O_APPEND;
        fileParams = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

        fd = open("audit.log", openFlags, fileParams);

        if (fd == -1) {
            printf("Error opening log file\n");
            exit(-1);
        }

        write(fd, argv[2], strlen(argv[2]));
        write(fd, "\n", 1);

        close(fd);
    }

    // ---------- VIEW ----------
    else if (strcmp(argv[1], "--view") == 0) {

        fd = open("audit.log", O_RDONLY);

        if (fd == -1) {
            printf("Error opening log file\n");
            exit(-1);
        }

        int line = 1;
        char lineBuf[20];

        sprintf(lineBuf, "%d: ", line);
        write(STDOUT_FILENO, lineBuf, strlen(lineBuf));

        while ((numRead = read(fd, buf, BUF_SIZE)) > 0) {

            for (int i = 0; i < numRead; i++) {

                write(STDOUT_FILENO, &buf[i], 1);

                if (buf[i] == '\n' && i != numRead - 1) {
                    line++;
                    sprintf(lineBuf, "%d: ", line);
                    write(STDOUT_FILENO, lineBuf, strlen(lineBuf));
                }
            }
        }

        close(fd);
    }

    else {
        printf("Invalid command\n");
    }

    return 0;
}
