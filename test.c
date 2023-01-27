#include "get_next_line.h"
#include <stdio.h>
char	*ft_cleaner_test(char *tmp)
{
	size_t		start;
	size_t		length;
    size_t      i;
	char		*new_stock;
//verif qvec strrchr que il a bien une newline dans la string
    start = 0;
	length = 0;
	if (!tmp)
		return (NULL);
	while (tmp[start] != '\n')
        start++;
    start++;
    printf("start = %zu", start);
	while (tmp[start + length] && tmp[start + length] != '\n')
		length++;
	new_stock = malloc(sizeof(char) * (length + 1));
	if (!new_stock)
		return (NULL);
	i = 0;
    while (i < length)
    {
        new_stock[i] = tmp[start + i];
        i++;
    }
    new_stock[i] = '\0';
	free(tmp);
	return (new_stock);
}

int main(void){
    char *result;
    char buffer[] = "42lol\ntest\ncaca";
    result = ft_cleaner_test(buffer);
    //printf("%s", result);
}