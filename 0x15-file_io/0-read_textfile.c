#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: Text file being read
 * @letters: Number of letters to be read.
 * Return: Actual number of bytes read and printed
 * or 0 when function fails or filename is NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return (0);

	int fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	char *buf = malloc(sizeof(char) * letters);

	if (buf == NULL)
	{
		close(fd);
		return (0);
	}

	ssize_t bytesRead = read(fd, buf, letters);

	if (bytesRead == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}

	ssize_t bytesWritten = write(STDOUT_FILENO, buf, bytesRead);

	if (bytesWritten == -1 || bytesWritten != bytesRead)
	{
		free(buf);
		close(fd);
		return (0);
	}

	free(buf);
	close(fd);
	return (bytesWritten);
}
