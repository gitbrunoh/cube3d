/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:39:51 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/10 20:20:03 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "headers.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_image
{
	void	*img;
	int		**tex;
	char	*path;
	int		width;
	int		height;
	int		print_x;
	int		print_y;
}	t_image;

typedef struct s_sprite
{
	t_image	*sprite_sheet;
	long	last_frame_time;
	long	frame_time;
	int		frame_w;
	int		frame_h;
	int		num_frames;
	int		cur_frame;
	float	sprt_scl;
	int		frame_y;
	int		new_w;
	int		new_h;
	int		start_x;
	int		start_y;
}	t_sprite;

typedef struct s_fixed
{
	const int	bits;
	int			fixed_point;
	int			(*to_int)(void);
	float		(*to_float)(void);
	int			(*get_raw_bits)(void);
	void		(*set_raw_bits)(int const raw);
}	t_fixed;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	int		step_x;
	int		step_y;
	int		side;
	int		hit;
}	t_ray;

typedef struct s_dir_vector
{
	double	x;
	double	y;
}	t_dir_vector;

typedef struct s_player
{
	t_dir_vector	*dir_vector;
	t_dir_vector	*cam_vector;
	t_image			*sword;
	t_sprite		*attack;
	double			p_y;
	double			p_x;
	char			p_dir;
	t_ray			*ray; // for collision
	bool			is_attacking;
}	t_player;

typedef struct s_color
{
	char	*input;
	int		color;
	int		red;
	int		green;
	int		blue;
}	t_color;

typedef struct s_texture
{
	t_color	*ceiling;
	t_color	*floor;
	t_image	*north;
	t_image	*south;
	t_image	*east;
	t_image	*west;
	t_image	*door;
}	t_texture;

typedef struct s_map
{
	t_player		*player;
	t_texture		*texture;
	void			*black_img;
	void			*white_img;
	char			**map;
	char			**ff_map;
	char			*path;
	unsigned int	rows;
	unsigned int	cols;
}	t_map;

typedef struct s_frame_time
{
	struct timeval	start;
	struct timeval	end;
	double			frame_time;
	double			move_speed;
	double			rot_speed;
}	t_frame_time;

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	e;
	bool	c;
	bool	left;
	bool	right;
	bool	esc;
	bool	shift;
}	t_keys;

typedef struct s_cub
{
	t_map			*map;
	void			*mlx_ptr;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				mouse_x;
	int				mouse_y;
	char			*file;
	char			*line;
	int				fd;
	t_frame_time	frame_time;
	t_keys			keys;
}	t_cub;

typedef struct s_column
{
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_x;
	int			*buffer;
}	t_column;

#endif