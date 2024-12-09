/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:16:11 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/07 19:00:04 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h> // to use the LONG_MAX and LONG_MIN macros
# include <sys/types.h> // to use the MACRO WIFEXITED
# include <sys/wait.h> // to use the MACRO UNTRACED
# include <signal.h> // to use the signal function
# include <errno.h> // to use the errno variable
# include <string.h> // to use the strerror function
# include <fcntl.h> // to use the open function
# include <sys/stat.h> // to use the stat function
# include <dirent.h> // to use the opendir function
# include <termios.h> // to use the termios structure
# include "libs/minilibx-linux/mlx.h" // to include the mlx library
# include "libs/minilibx-linux/mlx_int.h" // to include the mlx library
# include "libs/libft/libft.h" // to include the libft library
# include <stdarg.h> // to use the va_list type to ft_error_msg_construct
# include "structs.h" // to include the structs.h file
# include "macros.h" // to include the macros.h file
# include "libs/get_next_line/get_next_line.h" // to include gnl function
# include "functions.h" // to include the functions.h file
# include <math.h> // to use the math functions

#endif