#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char buffer[256];
	int bytesRead;

	fd = open("text.txt", O_RDONLY);
	// Read from stdin (file descriptor 0)
	while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
		buffer[bytesRead] = '\0';  // Null-terminate the string
		printf("%s\n", buffer); // Output the content
	}
	return (0);
}
