// C program to read nth byte of a file and
// copy it to another file using lseek
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

// Driver code
int main()
{
    //
    char arr[100];

    // Open the file for READ only.
    int f_write = open("start.txt", O_RDONLY);

    // Open the file for WRITE and READ only.
    int f_read = open("end.txt", O_WRONLY);

    // read all of the bytes
    while (read(f_write, arr, 1))
    {
        lseek(f_write, 0, SEEK_CUR);
        write(f_read, arr, 1);
    }

    close(f_write);
    close(f_read);

    return 0;
}