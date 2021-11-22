#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include <fcntl.h> 

int	main()
{
	int	fd = open("foo.txt", O_CREAT);
	char *d;
	char *g;
	int	ca = read(fd, d, BZ);
	printf("%d: %s\n", ca, d);
	ca = read(fd, d, BZ);
	printf("%d: %s\n", ca, d);

}
