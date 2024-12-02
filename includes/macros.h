/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:04:32 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/01 18:53:05 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

// SCREEN MACROS
# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480

// NAME
# define NAME "Cub3D"

// ERROR MACROS
# define ERROR_MSG ft_error_msg_construct
# define ERROR_PRINT ft_put_error_msg
# define ERROR_AC "Error\n Invalid number of arguments\n"
# define ERROR_OPEN "Error\n Unable to open file \""
# define ERROR_EXT "Error\n Invalid file extension for file \""
# define ERROR_READ "Error\n Empty file \""
# define ERROR_MLC "Error\n Memory allocation failed \""
# define ERROR_MAP_EMPTY "Error\n Invalid map: empty line in map content\n"
# define ERROR_MAP_CLOSE "Error\n Invalid map: map not closed\n"
# define ERROR_MAP_CHAR "Error\n Invalid map: invalid character in map\n"
# define ERROR_TEXT "Error\n Invalid texture path: \""
# define ERROR_NULL_TEXT "Error\n Missing texture or color\n"
# define ERROR_SPLIT "Error\n Unable to split line\n"
# define ERROR_PLAYER "Error\n Invalid amount of players\n"
# define ERROR_MAP_SIZE "Error\n Invalid map size\n"
# define ERROR_MLX "Error\n Unable to initialize mlx\n"
# define ERROR_WIN "Error\n Unable to create window\n"
# define ERROR_IMG "Error\n Unable to create image\n"

// MLX MACROS
# define MLX_NW mlx_new_window
# define MLX_GTA mlx_get_data_addr
# define MLX_PITW mlx_put_image_to_window
# define MLX_NI mlx_new_image

#endif