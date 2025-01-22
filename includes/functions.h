/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:00:05 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/13 16:07:24 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "headers.h"

// RAY CASTING
int			ft_ray_casting(t_cub *cub);
void		ft_draw_column(t_cub *cub, int x, t_player *player);
void		ft_fill_buffer(t_column *column, t_ray *ray, t_cub *cub);
void		ft_shading(int *buffer, int len, double orto_wall_dist);

// COLLISION 
int			ft_collision(t_map *map, t_cub *cub);
int			ft_collision_dda(t_player *player, t_cub *cub);
void		ft_collision_dists(t_player *player);
void		ft_prepare_vec(double angle, t_dir_vector *dir_vector, t_cub *cub);

// DRAW UTILS
void		calculate_delta_distances(t_ray *ray);
void		calculate_ray_direction(int x, t_ray *ray, t_player *player);
void		calculate_initial_distances(t_player *player, t_ray *ray);
void		ft_perform_dda(t_cub *cub, t_ray *ray);

// UTILS FUNCTIONS
void		ft_rotate_vect(double angle, t_dir_vector *vector);
double		ft_deg_to_rad(double deg);
bool		ft_is_walkable(char c);
bool		ft_perpendicular_vect(t_dir_vector *dir_vector, \
t_dir_vector *cam_vector);

// FREE FUNCTIONS
void		ft_clear_cub(void);
void		ft_clear_map(t_map *map);
void		ft_free_int_array(int **array, int w);

// ERROR FUNCTIONS
char		*ft_error_msg_construct(int nbr, ...);
int			ft_put_error_msg(char *error_msg, int exit_status);

// PARSE FUNCTIONS
void		ft_validate_extension(char *name, char *ext);
void		ft_input_parse(char **av, int ac);
void		ft_input_validation(char **av, int ac);
void		ft_parse_texture(void);
void		ft_parse_color(t_cub *cub, char *line);
void		ft_normalize_map(t_cub *cub);
void		ft_get_tex_imgs(t_cub *cub, t_texture *texture);

// CHECK COLORS
void		ft_check_dup_color(t_color *color, char *line, char **split);
void		ft_check_errors(t_cub *cub, char **split);

// CUB FUNCTIONS
t_cub		*ft_get_cub(void);
t_cub		*ft_init_cub(void);

// TEXTURE FUNCTIONS
t_texture	*ft_init_texture(void);
void		ft_get_text_color(t_map *map, char **split);
bool		ft_is_text_or_color(char *line, t_cub *cub, bool parse);
void		ft_get_tex_imgs(t_cub *cub, t_texture *texture);

// MAP FUNCTIONS
void		ft_init_map(t_cub *cub);
void		ft_alloc_map(t_cub *cub);
void		ft_get_map_textures(t_map *map, char *line);
void		ft_trim_map(t_cub *cub);
void		ft_look_for_invalid_map(t_cub *cub);

// FLOODFILL FUNCTIONS
void		ft_call_flood(t_map *map);

// COLOR FUNCTIONS
t_color		*ft_init_color(void);
void		ft_create_colors(t_cub *cub, char *line);
int			ft_create_rgb(int r, int g, int b);

// PLAYER FUNCTIONS
void		ft_check_player(t_map *map);

// MLX FUNCTIONS
void		ft_init_mlx(t_cub *cub);
void		ft_mlx_hook_and_loop(t_cub *cub);

// MLX HOOKS
int			ft_close_x(t_cub *cub);
int			ft_keys(t_cub *cub);
void		ft_my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
int			ft_ray_casting(t_cub *cub);
int			ft_mouse(int x, int y, t_cub *cub);
int			ft_key_press(int keycode, t_cub *cub);
int			ft_key_release(int keycode, t_cub *cub);

// MLX UTILS
void		ft_draw_vertical_line(int x, t_column *column, t_cub *cub);
int			**ft_get_image_pixels(t_img *img, int w, int h);

// KEYS
void		ft_rotate_left(t_player *player, t_cub *cub);
void		ft_rotate_right(t_player *player, t_cub *cub);
void		ft_open_door(t_cub *cub);
void		ft_close_door(t_cub *cub);

// MLX IMAGE FUNCTIONS
void		ft_image_hub(t_cub *cub);

// MOVE FUNCTIONS
void		ft_map_move(t_cub *cub);
void		ft_move_forward(t_cub *cub);
void		ft_move_backward(t_cub *cub);
void		ft_move_right(t_cub *cub);
void		ft_move_left(t_cub *cub);

// MOUSE FUNCTIONS
int			ft_mouse(int x, int y, t_cub *cub);
int			ft_mouse_click(int button, int x, int y, t_cub *cub);

// TIME FUNCTIONS
void		ft_start_frame(t_frame_time *frame_time);
void		ft_end_frame(t_frame_time *frame_time);
long		ft_get_time_s(void);

// SWORD FUNCTIONS
void		ft_draw_sword(t_image *sword, int w, int h, float scale);
void		draw_frame(t_cub *cub, t_player *player);

// MINIMAP
void		ft_draw_minimap(t_cub *cub, t_player *player);

// SPRITES
void		draw_sword_attack(t_cub *cub, t_player *player);
void		update_animation(t_sprite *anim);
t_sprite	*init_sprite(t_image *ss, int frame_w, int frame_h, int num_frames);
t_image		*load_sprite_sheet(void *mlx_ptr, char *path, \
int width, int height);

#endif