/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:16:11 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/05 16:11:36 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h> // to use the open function
# include <math.h>
# include <stdarg.h> // to use the va_list type to ft_error_msg_construct
# include "libs/minilibx-linux/mlx.h"
# include "libs/minilibx-linux/mlx_int.h"
# include "structs.h"
# include "libs/libft/libft.h"
# include "macros.h"
# include "libs/get_next_line/get_next_line.h"
# include "functions.h"
# include <sys/time.h> // to use the gettimeofday function

#endif