#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

static int exec_prog(const char **argv)
{
    pid_t my_pid;
    int status, timeout /* unused ifdef WAIT_FOR_COMPLETION */;

    if (0 == (my_pid = fork()))
    {
        if (-1 == execve(argv[0], (char **)argv, NULL))
        {
            perror("child process execve failed [%m]");
            return -1;
        }
    }
    return 0;

#ifdef WAIT_FOR_COMPLETION
    timeout = 1000;

    while (0 == waitpid(my_pid, &status, WNOHANG))
    {
        if (--timeout < 0)
        {
            perror("timeout");
            return -1;
        }
        sleep(1);
    }

    printf("%s WEXITSTATUS %d WIFEXITED %d [status %d]\n",
           argv[0], WEXITSTATUS(status), WIFEXITED(status), status);

    if (1 != WIFEXITED(status) || 0 != WEXITSTATUS(status))
    {
        perror("%s failed, halt system");
        return -1;
    }

#endif
    return 0;
}

int main()
{
    char *cmd1 = NULL;
    char *cmd2 = NULL;
    const char *my_argv[64] = {"/bin/ls", cmd1, cmd2, NULL};
    int rc = exec_prog(my_argv);
}