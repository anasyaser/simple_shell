#include "header.h"


int main()
{
       /* 	char *resl; */
/* 	char *arg[]; */
/* 	int i = 0 */
/* 	resl = read_input(); */
/* 	arg = get_tokens(resl); */
/* 	printf("%s\n", resl); */
/* 	while (arg[i]) */
/* 	{ */
		
/* 	} */
/* 	return (0); */
/* } */
	char *args[] = {"ls", "-l", NULL};
	execve(args[0], args, NULL);
	return (0)
}
