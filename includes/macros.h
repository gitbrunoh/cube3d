/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:04:32 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/13 13:24:43 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

// CONSTANTS
# define MOVE_FACTOR 6
# define ROTATE_FACTOR 5
# define SHADE_FACTOR 0.02

// FIXED POINT MACROS
# define F_BITS 8

// MINIMAP MACROS
# define MINIMAP_SIZE 200     // Tamanho do minimap quadrado
# define PLAYER_MARKER_SIZE 4 // Tamanho do player sprite
# define MINIMAP_MARGIN 20    // margem da janela da window
# define MINIMAP_SCALE 0.9    // escala do minimap
# define TILE_SIZE 10         // tamanho de cada quadricula

// KEY MACROS
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_SPC 32
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_E 101
# define KEY_C 99
# define KEY_SHIFT 65505

// NUMBER MACROS
//# define ROTATION_ANGLE 0.2
# define PI 3.14159265358979323846

// EVENT MASKS
# define KEYPRESS_MASK 0x01
# define KEYRELEASE_MASK 0x02
# define BUTTONPRESS_MASK 0x04
# define POINTERMOTION_MASK 0x40

// SCREEN MACROS
# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 600

// TEXTURE MACROS
# define TEX_WIDTH 32
# define TEX_HEIGHT 32

// SWORD MACROS
# define SWORD_WIDTH 64
# define SWORD_HEIGHT 64

// SPRITE MACROS
# define SPRITE_WIDTH 192
# define SPRITE_HEIGHT 64
# define SPRITE_LEN 3
# define SPRITE_FRAME_TIME 120

// COLORS
# define NONE -16777216

// NAME
# define NAME "Cub3D"
# define TITLE "Cub3d brunhenr e ncampbel - 42Lisboa"

// ERROR MACROS
# define ERROR_MSG ft_error_msg_construct
# define ERROR_PRINT ft_put_error_msg
# define ERROR_AC "Error\n Invalid number of arguments\n"
# define ERROR_OPEN "Error\n Unable to open file \""
# define ERROR_EXT "Error\n Invalid file extension for file \""
# define ERROR_READ "Error\n Empty file \""
# define ERROR_MLC "Error\n Memory allocation failed \""
# define ERROR_MAP_EMPTY "Error\n Invalid map: empty line in map content\n"
# define ERROR_MAP_DOOR "Error\n Invalid map: door texture is missing\n"
# define ERROR_MAP_CLOSE "Error\n Invalid map: map not closed\n"
# define ERROR_MAP_CHAR "Error\n Invalid map: invalid character in map\n"
# define ERROR_MAP_ORDER "Error\n Invalid map: map order\n"
# define ERROR_KEY "Error\n Invalid keyword\n"
# define ERROR_MAP_DUPLICATE "Error\n Invalid map: duplicated keyword\n"
# define ERROR_TEXT "Error\n Invalid texture path: \""
# define ERROR_NULL_TEXT "Error\n Missing texture or color\n"
# define ERROR_COL_RANGE "Error\n Color component is out of range\n"
# define ERROR_COL_NUM "Error\n Color number contains non digit char\n"
# define ERROR_SPLIT "Error\n Unable to split line\n"
# define ERROR_PLAYER "Error\n Invalid amount of players\n"
# define ERROR_MAP_SIZE "Error\n Invalid map size\n"
# define ERROR_MLX "Error\n Unable to initialize mlx\n"
# define ERROR_WIN "Error\n Unable to create window\n"
# define ERROR_IMG "Error\n Unable to create image\n"
# define ERROR_GDA "Error\n Unable to get data address\n"
# define ERROR_VECTORS "Error\n The vectors are not perpendicular.\n"

// MLX MACROS
# define MLX_NW mlx_new_window
# define MLX_GDA mlx_get_data_addr
# define MLX_PITW mlx_put_image_to_window
# define MLX_XFTI mlx_xpm_file_to_image
# define MLX_NI mlx_new_image

#endif