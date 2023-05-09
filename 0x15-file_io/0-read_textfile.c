#include "main.h"
#include <stdlib>

/**
 * read_textfile - Reads a text file and prints to STDOUT.
 * @filename: Name of text file to be read.
 * @letters: Number of letters to be read.
 *
 * Return: Number of bytes read and printed to STDOUT.
 * 0 if function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buf;
	ssize_t t, w;

	if (filename == NULL)
	{
		fprintf(stderr, "Error: Filename cannot be NULL.\n");
		return (0);
	}

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error opening file %s: %s\n", filename, strerror(errno));
		return (0);
	}

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		fprintf(stderr, "Error allocating memory for buffer.\n");
		close(fd);
		return (0);
	}

	t = read(fd, buf, letters);
	if (t == -1)
	{
		fprintf(stderr, "Error reading from file %s: %s\n", filename, strerror(errno));
		free(buf);
		close(fd);
		return (0);
	}

	w = write(STDOUT_FILENO, buf, t);
	if (w == -1)
	{
		fprintf(stderr, "Error writing to STDOUT: %s\n", strerror(errno));
		free(buf);
		close(fd);
		return (0);
	}

	free(buf);
	close(fd);

	return (w);
}
