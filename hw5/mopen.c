/* test of multiple open() calls for same file 
   args:  filename, followed by 0 or more switches 
          -r  for O_RDONLY,  -w  for O_WRONLY,  -rw  for O_RDWR
   this program attempts to open arg1 once for each switch supplied, 
   but always at least twice.  Default flag is O_RDONLY */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAXSTRING 100 /* maximum size for strings */

/* try_open
     2 args:  file name (string), value for flags 
     return:  return value from open
     state change:  return from open() is printed on standard output */
int try_open(char *filename, int FLAGS)
{
    char *flagstr; /* representation of FLAGS as a string */
    int ret_val;   /* return value from open() */

    switch (FLAGS)
    {
    case O_RDONLY:
        flagstr = "O_RDONLY";
        break;
    case O_WRONLY:
        flagstr = "O_WRONLY";
        break;
    case O_RDWR:
        flagstr = "O_RDWR";
        break;
    default:
        printf("try_open:  unrecognized flag %d\n", FLAGS);
        exit(1);
        break;
    }
    printf("open(%s, %s) returned ", filename, flagstr);
    if ((ret_val = open(filename, FLAGS)) < 0)
    {
        printf("error %d\n", ret_val);
        perror("try_open: ");
    }
    else
        printf("file descriptor %d\n", ret_val);
    return ret_val;
}

int main(int argc, char *argv[])
{
    char *filename;           /* name of file to be multiply opened */
    char *progname = argv[0]; /* name of this program */
    char *getlinebuff = NULL;
    size_t getlinelen = 0;
    int f_write;

    if (argc == 1)
    {
        printf("usage:  %s filename [ -r|-w|-rw ] ...\n", progname);
        exit(1);
    }
    /* at least one command-line arg was provided*/

    filename = argv[1];
    argv += 2;
    argc -= 2;
    /* there are argc switches, beginning at argv[0] */

    switch (argc)
    {
    case 0:
        try_open(filename, O_RDONLY);
        try_open(filename, O_RDONLY);
        break;

    case 1:
        try_open(filename, O_RDONLY);

    default:
        while (*argv)
        {
            if (!strcmp("-r", argv[0]))
                try_open(filename, O_RDONLY);
            else if (!strcmp("-w", argv[0]))
                try_open(filename, O_WRONLY);
            else if (!strcmp("-rw", argv[0]))
                try_open(filename, O_RDWR);
            else
            {
                fprintf(stderr, "Unrecognized switch \"%s\" -- aborting\n",
                        argv[0]);
                exit(1);
            }
            /* switch was valid */
            argv++;
        }
        break;
    }
    printf("Enter commands using the following syntax:  (count < %d)\n",
           MAXSTRING);
    printf("\tread <fd> <count>\n\twrite <fd> <string>\n\tdup\n\tquit\n");
    while (1)
    {
        char cmd[MAXSTRING];  /* command entered by user */
        int fd;               /* file descriptor entered by user */
        char buff[MAXSTRING]; /* a string buffer for I/O */
        int ret_val;          /* return value from a system call */

        printf("read write quit:  ");
        if ((ret_val = scanf("%s", cmd)) == EOF)
            exit(0);
        /* assert:  one word was read into cmd */

        /***** read command *****/
        if (!strcmp(cmd, "read"))
        {
            int count; /* number of chars to read */

            scanf("%d %d", &fd, &count);
            if (count >= MAXSTRING)
            {
                printf("%d is too many characters -- try reading fewer than %d\n",
                       count, MAXSTRING);
                continue;
            }
            /* count is small enough */
            if ((ret_val = read(fd, buff, count)) < 0)
                printf("Error code %d returned\n", ret_val);
            else
            {
                buff[ret_val] = '\0';
                printf("%d bytes were read:  \"%s\"\n", ret_val, buff);
            }

            /***** write command *****/
        }
        else if (!strcmp(cmd, "write"))
        {
            scanf("%d ", &fd);
            int nchars = getline(&getlinebuff, &getlinelen, stdin);
            if ((ret_val = write(O_RDONLY, getlinebuff, nchars - 1)) < 0)
                printf("Error code %d returned\n", ret_val);
            else
                printf("%d bytes written\n", ret_val);

            /***** quit command *****/
        }
        else if (!strcmp(cmd, "quit"))
        {
            break;
        }
        else if (!strcmp(cmd, "lseek"))
        {
            char arr[100];

            // Open the file for READ only.
            int f_write = open(filename, O_RDONLY);

            // Open the file for WRITE and READ only.
            int f_read = open(filename, O_WRONLY);

            // read all of the bytes
            while (read(f_write, arr, 1))
            {
                lseek(f_write, 2, SEEK_CUR);
                write(f_read, arr, 1);
            }

            close(f_write);
            close(f_read);
        }
        else if (!strcmp(cmd, "dup"))
        {
            // open() returns a file descriptor file_desc to a
            // the file "dup.txt" here"

            int file_desc = open(filename, O_WRONLY | O_APPEND);

            if (file_desc < 0)
                printf("Error opening the file\n");

            // dup() will create the copy of file_desc as the copy_desc
            // then both can be used interchangeably.

            int copy_desc = dup(file_desc);

            // write() will write the given string into the file
            // referred by the file descriptors

            write(copy_desc, "This will be output to the file named dup.txt\n", 46);

            write(file_desc, "This will also be output to the file named dup.txt\n", 51);
        } 
        else if(!strcmp(cmd, "close")) 
        {
            int closeValue = close(ret_val);
            if(closeValue == -1) {
                printf("Unable to close file\n");
            } else {
                printf("Successfully closed file\n");
                // break;
            };
        }

        else
            printf("Unrecognized command %s\n", cmd);
    }

    free(getlinebuff);
    exit(0);
}
