// #include <stdio.h>
// #include <unistd.h>
// #include "get_next_line.h"
// int main(void)
// {
//     char *line;

//     while (line = get_next_line(0))
//     {
//         printf("LINE: %s", line);
//         free(line);
//     }
// }
// // #include <fcntl.h>
// // #include <fcntl.h>
// // #include <stdio.h>
// // #include <stdlib.h>
// // #include "get_next_line.h"

// // int	main(void)
// // {
// // 	int		fd1;
// // 	int		fd2;
// // 	int		fd3;
// // 	char	*line1;
// // 	char	*line2;
// // 	char	*line3;
// // 	int		i;

// // 	fd1 = open("file1.txt", O_RDONLY | O_CREAT, 0644);
// // 	fd2 = open("file2.txt", O_RDONLY | O_CREAT, 0644);
// // 	fd3 = open("file3.txt", O_RDONLY | O_CREAT, 0644);

// // 	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
// // 	{
// // 		perror("Error opening files");
// // 		return (1);
// // 	}

// // 	i = 1;
// // 	while (1)
// // 	{
// // 		line1 = get_next_line(fd1);
// // 		line2 = get_next_line(fd2);
// // 		line3 = get_next_line(fd3);

// // 		if (!line1 && !line2 && !line3)
// // 			break;

// // 		printf("Round %d\n", i++);
// // 		if (line1)
// // 		{
// // 			printf("File1: %s", line1);
// // 			free(line1);
// // 		}
// // 		if (line2)
// // 		{
// // 			printf("File2: %s", line2);
// // 			free(line2);
// // 		}
// // 		if (line3)
// // 		{
// // 			printf("File3: %s", line3);
