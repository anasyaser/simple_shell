#include "header.h"


int main()
{
	char *resl;
	char *args[2];
	int i = 0;
	while (1)
	{
		resl = read_input();
		get_args(resl, args);
		/* while (args[i]) */
		/* { */
		/* 	printf("%s\n", args[i]); */
		/* 	i++; */
		/* } */
		args[1] = NULL;
		execve(args[0], args, NULL);
		/* printf("User input:%s\n", resl); */
		free(resl);
	}

	return (0);
}
