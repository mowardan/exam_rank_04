// #include <unistd.h>
// #include <stdlib.h>

// // // int	ft_popen(const char *file, char *const argv[], char type)
// // // {
// // // 	if (!file || !argv || (type != 'r' && type != 'w'))
// // // 		return -1;
// // // 	int fd[2];
// // // 	pipe(fd);
// // // 	if (type == 'r')
// // // 	{
// // // 		if (fork() == 0)
// // // 		{
// // // 			dup2(fd[1], STDOUT_FILENO);
// // // 			close(fd[0]);
// // // 			close(fd[1]);
// // // 			execvp(file, argv);
// // // 			exit (-1);
// // // 		}
// // // 		close(fd[1]);
// // // 		return (fd[0]);
// // // 	}
// // // 	if (type == 'w')
// // // 	{
// // // 		if (fork() == 0)
// // // 		{
// // // 			dup2(fd[0], STDIN_FILENO);
// // // 			close(fd[0]);
// // // 			close(fd[1]);
// // // 			execvp(file, argv);
// // // 			exit (-1);
// // // 		}
// // // 		close(fd[0]);
// // // 		return (fd[1]);
// // // 	}
// // // 	return -1;
// // // }

// // // int main(void)
// // // {
// // //     return (1);
// // // }

// // int popen(const char *file, char *const av[], char type)
// // {
// // 	if(!file || !av || (type != 'r' && type !='w'))
// // 		return -1;
// // 	int fd[2];
// // 	pipe(fd);
// // 	if(type == 'r')
// // 	{
// // 		if(fork() == 0)
// // 		{
// // 			dup2(fd[1], 1);
// // 			close(fd[0]);
// // 			close(fd[1]);
// // 			execvp(file, av);
// // 			exit(-1);
// // 		}
// // 		close(fd[1]);
// // 		return(fd[0]);
// // 	}
// // 	if(type == 'w')
// // 	{
// // 		if(fork() == 0)
// // 		{
// // 			dup2(fd[0], 0);
// // 			close(fd[0]);
// // 			close(fd[1]);
// // 			execvp(file, av);
// // 			exit(-1);
// // 		}
// // 		close(fd[0]);
// // 		return(fd[1]);
// // 	}
// // 	return -1;
// // }


// // int main()
// // {
// // 	return(1);
// // }


// // int peopen(const char *file, char *const av[], char type)
// // {
// // 	if(!file || !av || (type != 'w' && type != 'r'))
// // 		return(-1);
// // 	int fd[2];
// // 	pipe(fd);
// // 	if(type == 'r')
// // 	{
// // 		if(fork() == 0)
// // 		{
// // 			dup2(fd[1], 1);
// // 			close(fd[0]);
// // 			close(fd[1]);
// // 			execvp(file, av);
// // 			exit(-1);
// // 		}
// // 		close(fd[1]);
// // 		return(fd[0]);
// // 	}
// // 	if(type == 'w')
// // 	{
// // 		if(fork() == 0)
// // 		{
// // 			dup2(fd[0], 0);
// // 			close(fd[0]);
// // 			close(fd[1]);
// // 			execvp(file, av);
// // 			exit(-1);
// // 		}
// // 		close(fd[0]);
// // 		return(fd[1]);
// // 	}
// // 	return -1;
// // }

// // int main()
// // {
// // 	return 1;
// // }

// // int popen(const char *file, char *const av[], char type)
// // {
// // 	if(!file || !av || (type != 'w' && type != 'r'))
// // 		return(-1);
// // 	int fd[2];
// // 	pipe(fd);
// // 	if(type == 'r')
// // 	{
// // 		if(fork() == 0)
// // 		{
// // 			dup2(fd[1], 1);
// // 			close(fd[0]);
// // 			close(fd[1]);
// // 			execvp(file, av);
// // 			exit(-1);
// // 		}
// // 		close(fd[1]);
// // 		return(fd[0]);
// // 	}
// // 	if(type == 'w')
// // 	{
// // 		if(fork() == 0)
// // 		{
// // 			dup2(fd[0], 0);
// // 			close(fd[0]);
// // 			close(fd[1]);
// // 			execvp(file, av);
// // 			exit(-1);
// // 		}
// // 		close(fd[0]);
// // 		return(fd[1]);
// // 	}
// // 	return(-1);
// // }


// // int main()
// // {
// // 	return(1);
// // }

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <wait.h>

// int picoshell(char **cmds[])
// {
// 	int res = 0;
// 	int prv_rfd = -1;
// 	pid_t pid;
// 	int i = 0;
// 	pid_t child_pids[128];
// 	int child_count = 0;
// 	int pipefd[2];

// 	while(cmds[i])
// 	{
// 		if(cmds[i + 1] && pipe(pipefd) == -1)
// 			return 1;
// 		pid = fork();
// 		if(pid == 0)
// 		{
// 			if(prv_rfd != -1)
// 			{
// 				dup2(prv_rfd, 0);
// 				close(prv_rfd);
// 			}
// 			if(cmds[i + 1])
// 			{
// 				dup2(pipefd[1], 1);
// 				close(pipefd[1]);
// 				close(pipefd[0]);
// 			}
// 			execvp(cmds[i][0], cmds[i]);
// 			exit(1);
// 		}
// 		child_pids[child_count++] = pid;
// 		if(prv_rfd != -1)
// 			close(prv_rfd);
// 		if(cmds[i + 1])
// 		{
// 			close(pipefd[1]);
// 			prv_rfd = pipefd[0];
// 		}
// 		i++;
// 	}

// 	int status;
// 	for(int j = 0;j < child_count;j++)
// 	{
// 		if(waitpid(child_pids[j], &status, 0) == -1)
// 			return 1;
// 		else if (WIFEXITED(status) && WEXITSTATUS(status))
// 			res = 1;
// 	}
// 	return res;
// }


int picoshell(char **cmds[])
{
	int fd[2];
	int save_fd = -1;
	for(int i = 0; cmds[i]; i++)
	{
		if(cmds[i + 1] && pipe(fd) == -1)
			{return 1;}
		if(fork() == 0)
		{
			dup2(save_fd, 0);
			if(cmds[i+1])
			{
				dup2(fd[1], 1);
				close(fd[0]);
				close(fd[1]);
			}
			if(i)
				close(save_fd);
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if(i)
			close(save_fd);
		if(cmds[i+1])
			close(fd[1]);
		save_fd = fd[0];
	}

	while(wait(NULL)!= -1)
	{};
	return 0;
}

int main()
{
	return(1);
}











