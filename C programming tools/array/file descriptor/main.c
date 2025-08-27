/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:28:47 by fbui-min          #+#    #+#             */
/*   Updated: 2025/04/14 18:12:07 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	// INITIALISE FD
	int	fd;

	// OPEN FD
	// open() -> fopen();

	// open file but diff operation
	fd = open("text.txt", O_RDONLY);
	printf("%d\n", fd); // operation 1 -> 3
	fd = open("text.txt", O_WRONLY);
	printf("%d\n", fd); // operation 2 -> 4
	if (fd < 0)
		return (1);

	// WRITE TO FD (REDIRECTING OUTPUT)
	// write() -> printf();

	// write to stdout (fd 1 - terminal)
	write(1, "abc\n", 4);
	// printf("%d\n", 1);

	// write to files
	write(fd, "abc\n", 4);

	// write to file in terminal
	// file.exe > destinational file

	// READ FROM FD (REDIRECTING OUTPUT)
	// read() -> scanf()/fget();

	// read from stdin (fd 0 - keyboard)
	char	buffer[256];
	size_t	byte_read;
	byte_read = read(0, buffer, sizeof(buffer) - 1); // read data up to buffer-1 from stdin, file, input source into buffer
	// file.exe -> keyboard input

	// read from files
	char	buffer[256];
	size_t	byte_read;
	byte_read = read(fd, buffer, sizeof(buffer) - 1);
	// pipe input into the program (echo command): echo "example" | file.exe

	// read from file in terminal
	// file.exe < destinational file

	// CLOSE FD
	// close() -> fclose();

	close(fd);
	return (0);
}
