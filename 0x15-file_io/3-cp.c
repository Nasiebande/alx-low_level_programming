#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * error_exit - Print error message and exit with specified code
 * @exit_code: The exit code
 * @format: The format string for error message
 */
void error_exit(int exit_code, const char *format, ...)
{
	dprintf(STDERR_FILENO, "Error: ");
	va_list args;
	va_start(args, format);
	vdprintf(STDERR_FILENO, format, args);
	va_end(args);
	exit(exit_code);
}

/**
 * cp - Copy the content of a file to another file
 * @file_from: The name of the source file
 * @file_to: The name of the destination file
 */
void cp(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, read_bytes, write_bytes;
	char buffer[BUFFER_SIZE];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Can't read from file %s\n", file_from);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_to == -1)
		error_exit(99, "Can't write to %s\n", file_to);

	while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		write_bytes = write(fd_to, buffer, read_bytes);
		if (write_bytes == -1)
			error_exit(99, "Can't write to %s\n", file_to);
	}

	if (read_bytes == -1)
		error_exit(98, "Can't read from file %s\n", file_from);

	if (close(fd_from) == -1)
		error_exit(100, "Can't close fd %d\n", fd_from);

	if (close(fd_to) == -1)
		error_exit(100, "Can't close fd %d\n", fd_to);
}

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: The array of command-line arguments
 * Return: 0 on success, other values on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to\n");

	cp(argv[1], argv[2]);

	return (0);
}
