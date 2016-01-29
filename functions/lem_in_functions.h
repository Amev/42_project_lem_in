#ifndef LEM_IN_FUNCTIONS_H
# define LEM_IN_FUNCTIONS_H

# include "../libft/libft.h"

void				lem_in_print_error();
char				**lem_in_join_line(char **line, char ***read);
int					lem_in_str_is_all_num(char *str);
int					lem_in_is_hall_line(char *line);
int					lem_in_is_tube_line(char *line);
void				lem_in_print_entry(char **read);

#endif
