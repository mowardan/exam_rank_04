// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>
// #include <stdio.h>
// #include <wait.h>

// int picoshell(char **cmds[])
// {
//     int res = 0;
//     int prev_read_fd = -1;
//     int pipe_fd[2];
//     pid_t pid;
//     int i = 0;
//     pid_t child_pids[128];
//     int child_count = 0;

//     while (cmds[i])
//     {
//         if (cmds[i + 1] && pipe(pipe_fd) == -1)
//             return 1;
//         pid = fork();
//         if (pid == -1)
//             return 1;
//         if (pid == 0)
//         {
//             if (prev_read_fd != -1)
//             {
//                 dup2(prev_read_fd, STDIN_FILENO);
//                 close(prev_read_fd);
//             }
//             if (cmds[i + 1])
//             {
//                 dup2(pipe_fd[1], STDOUT_FILENO);
//                 close(pipe_fd[1]);
//                 close(pipe_fd[0]);
//             }
//             execvp(cmds[i][0], cmds[i]);
//             exit(1);
//         }
//         child_pids[child_count++] = pid;
//         if (prev_read_fd != -1)
//             close(prev_read_fd);
//         if (cmds[i + 1])
//         {
//             close(pipe_fd[1]);
//             prev_read_fd = pipe_fd[0];
//         }
//         i++;
//     }
//     int status;
//     for (int j = 0; j < child_count; j++)
//     {
//         if (waitpid(child_pids[j], &status, 0) == -1)
//             return 1;
//         else if (WIFEXITED(status) && WEXITSTATUS(status))
//             res = 1;
//     }
//     return res;
// }




int picoshell(char **cmds[])
{
    int fd[2];
    int save_fd = 0;
    for (int i = 0; cmds[i]; i++){
        if (cmds[i + 1] && pipe(fd) == -1){return 1;}
        if (fork() == 0)
        {
            dup2(save_fd, 0);
            if (cmds[i + 1]){
                dup2(fd[1], 1);
                close (fd[0]);
                close (fd[1]);
            }
            if (i) {close (save_fd);}
            execvp(cmds[i][0], cmds[i]);
            exit (1);
        }
        if (i)
            close (save_fd);
        if (cmds[i + 1])
            close(fd[1]);
        save_fd = fd[0];
    }
    while (wait(NULL) != -1);
    return 0;
}