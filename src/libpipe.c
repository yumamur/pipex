#include "../include/pipex.h"

char	*ft_strdup(char *str)
{
	int		i;
	char	*ret;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i++])
		;
	ret = malloc(i + 1);
	i = -1;
	while (str[++i])
		ret[i] = str[i];
	ret [i] = 0;
	return (ret);
}

char	*strjoin(const char *s1, const char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*r;

	if (!s1 || !s2)
		return (NULL);
	l1 = 0;
	while (s1[l1++])
		l2 = 0;
	while (s2[l2++])
		;
	r = (char *)malloc((l1 + l2 + 1) * sizeof(*s1));
	if (!r)
		return (NULL);
	while (*s1 != '\0')
		*(r++) = *((char *)s1++);
	while (*s2 != '\0')
		*(r++) = *((char *)s2++);
	*r = '\0';
	return (r - l1 - l2);
}

char	*p_substr(char *envp[], char *sub)
{
	int		l;
	int		i;
	char	*ret;

	if (!envp || !sub)
		return (NULL);
	l = -1;
	while (envp[++l])
	{
		i = 0;
		while (sub[i] == envp[l][i])
			if (sub[i++] == 0)
				return (ft_strdup(envp[l + i]));
	}
}
