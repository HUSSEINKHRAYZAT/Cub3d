/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:14:20 by afayad            #+#    #+#             */
/*   Updated: 2025/03/09 19:57:11 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <limits.h>

# define WIN_WIDTH 1800
# define WIN_HEIGHT 900
# define SPEED 0.09
# define ROT_SPEED 0.02

typedef struct s_ray
{
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	double		wall_x;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_num;
	int			texx;
	int			texy;
}	t_ray;

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}	t_list;

typedef struct s_player
{
	char		dir;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			move_x;
	int			move_y;
	int			rotate;
}	t_player;

typedef struct s_texture
{
	void		*img[4];
	char		*address[4];
	int			bpp;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}	t_texture;

typedef struct s_tools
{
	char		**file_matrix;
	char		**map_matrix;
	char		*map_path;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*file_content;
	char		*gun_addr;
	char		**map;
	char		*addr;
	void		*mlx;
	void		*win;
	void		*gun_img;
	void		*img;
	int			*floor;
	int			*back;
	int			bpp;
	int			line_length;
	int			endian;
	int			gun_bpp;
	int			gun_line_length;
	int			gun_endian;
	int			gun_width;
	int			gun_height;
	int			pitch;
	t_texture	texture;
	t_player	player;
	t_list		*list;
}	t_tools;

char	**ft_split(char *s, char c);
char	*ft_folder_maps(char *folder, char *str);
char	*ft_readfile(char *filename);
char	*ft_remove_spaces(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strskip(char *str, size_t size);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*get_line(char **map, int index, int ignore);
char	*extract_path_from_list(t_list *list, int index, int skip_chars);
int		*get_array(t_tools *tools, int index);
int		*get_rgb_values(t_tools *tools);
int		check_algo(char **map);
int		check_content(t_list *lst, char *check, int index);
int		check_filename(char *filename, int cub);
int		count_lines_list(t_list *list);
int		count_linked_list(t_list *start);
int		ft_atoi(char *str);
int		ft_count_char(char *str, char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		init_directions(t_tools **tools);
int		init_filetools(t_tools **tools, char *filename);
int		init_map(t_tools **tools);
int		init_player(t_tools *tools);
int		init_tools(t_tools **tools, char *filename);
int		is_all_digits(const char *str);
int		valid_map(char **map);
int		init_player(t_tools *tools);
int		*extract_color_from_list(t_list *list, int index);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
t_list	*ft_file_to_list(char *content, int check);
void	*ft_memcpy(void *dest, void *src, size_t n);
void	cleanup_tools(t_tools **tools);
void	free_array(char **env_array);
void	free_list(t_list *list);
void	ft_print_list(t_list *list);
void	init_null(t_tools **tools);
void	print_double_ptr(char **args);
void	v_strcat(char *dest, char *src);
void	v_strcpy(char *dest, char *src);
void	v_strncat(char *dest, const char *src, size_t n);
void	v_strncpy(char *dest, const char *src, size_t n);
void	delete_list(t_list *list);
void	replace_spaces(t_tools *tools);
char	*extract_path_from_list(t_list *list, int index, int skip_chars);
int		*extract_color_from_list(t_list *list, int index);
int		close_window(t_tools *data);
int		count_double_ptr(char **ptr);
int		find_player(t_tools *data);
int		game_loop(t_tools *data);
int		init_player(t_tools *data);
int		key_press(int key, t_tools *data);
int		key_release(int key, t_tools *data);
int		mouse_move(int x, int y, t_tools *data);
int		validate_player_pos(t_tools *data, int x, int y);
void	calculate_texture_x(t_ray *ray, t_tools *data);
void	calculate_wall_distance(t_ray *ray, t_tools *data);
void	cast_rays(t_tools *data);
void	clear_image(t_tools *data);
void	delete_list(t_list *list);
void	determine_texture_coordinates(t_ray *ray, t_tools *data);
void	determine_texture_number(t_ray *ray);
void	draw_floor_and_sky(t_tools *data);
void	draw_transparent_gun(t_tools *data);
void	draw_wall(t_ray *ray, t_tools *data, int x);
void	error(char *msg);
void	init_ray(t_ray *ray, t_tools *data, int x);
void	load_textures(t_tools *data);
void	mrotate_player(t_player *p, double angle);
void	perform_dda(t_ray *ray, t_tools *data, int map_width, int map_height);
void	put_pixel_to_image(t_tools *data, int x, int y, int color);
void	render_frame(t_tools *data);
void	set_player_dir(t_player *p, char dir);
void	set_player_direction(t_player *p, char dir);
void	set_player_plane(t_player *p, char dir);
void	update_player(t_tools *data);
void	calculate_ray_direction(t_ray *ray, t_tools *data, int x);
void	init_map_coordinates(t_ray *ray, t_tools *data);
void	init_hit_flag(t_ray *ray);
void	determine_step_and_side_distances(t_ray *ray, t_tools *data);
void	calculate_delta_distances(t_ray *ray);
int		init_directions_helper(t_list *tmp_list, t_tools *tools, int check);
void	free_map(char **map);
void	free_matrix(char **matrix);

#endif
