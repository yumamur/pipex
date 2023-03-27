#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

void	handle_error(char str[]);
char	*getpath(char *cmd, char *envp[]);
char	**p_split(const char *str, char c);
char	*p_substr(char *envp[], char *sub);
char	*ft_strdup(char *str);
char	*strjoin(const char *s1, const char *s2);

#endif
