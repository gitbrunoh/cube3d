/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:50:13 by ncampbel          #+#    #+#             */
/*   Updated: 2024/12/08 08:25:22 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers.h"

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
    {
		write (2, "Error: my_mlx_pixel_put\n", 24);
		return;
	}

	if (!cub->addr)
    {
        perror("Error: cub->addr is not initialized");
        return;
    }
	
	// if ((x >= 0 && x < SCREEN_WIDTH) && (y >= 0 && y < SCREEN_HEIGHT))
	// {
	dst = cub->addr + (y * cub->line_lenght + x * (cub->bpp / 8));
	*(unsigned int *)dst = color;
	// }
}

void	draw_vertical_line(int x, int drawStart, int drawEnd, int color, t_cub *cub)
{
	// Verifica se drawStart e drawEnd estão dentro dos limites da tela
	if (drawStart < 0)
		drawStart = 0;
	if (drawEnd >= SCREEN_HEIGHT)
		drawEnd = SCREEN_HEIGHT - 1;

	// Desenha a linha vertical pixel por pixel
	for (int y = drawStart; y <= drawEnd; y++)
	{
		my_mlx_pixel_put(cub, x, y, color);
	}
}

static void player_dir(double *p_dirX, double *p_dirY, t_cub *cub)
{
	if (cub->map->player->p_dir == 78)
	{
		*p_dirX = -1;
		*p_dirY = 0;
	}
}

static int	draw(t_cub *cub)
{
	//Pegando a posição do player e passando pra double. É preciso mesmo?
	double p_posX; //posição do player
	double p_posY; //posição do player
	p_posX = cub->map->player->p_x + 0.5; //PULO DO GATO. O player é representado por um ponto no mapa. O +0.5 é para centralizar o player no quadrado do mapa.
	p_posY = cub->map->player->p_y + 0.5;
	printf("POSITION OF THE PLAYER: p_posX: %f, p_posY: %f\n", p_posX, p_posY);

	//Definindo a direção do player com base no map 
	double p_dirX; //direção do player
	double p_dirY; //direção do player
	player_dir(&p_dirX, &p_dirY, cub);
	printf("DIRECTION OF THE PLAYER: p_dirX: %f, p_dirY: %f\n", p_dirX, p_dirY);

	//Definindo o plano -linha- da camera. Definir uma macro para a camera_lineY.
	double camera_lineX = 0; //direção da plano -linha- da camera
	double camera_lineY = 0.66; //direção do plano -linha- da camera

	//Direção do raio será calculada para cada coluna da tela
	double r_dirX; //direção do raio
	double r_dirY; //direção do raio

	double param = 0; //parametro para calcular a direção do raio
	int	x = 0; //contador
	
	while (x < SCREEN_WIDTH)
	{
		param = (2 * x / (double)SCREEN_WIDTH) - 1;
		
		//soma de 2 vetores. Mas cada x tem multiplicador diferente para o vetor da camera
		r_dirX = p_dirX + (param * camera_lineX);
		r_dirY = p_dirY + (param * camera_lineY);

		printf("r_dirX: %f, r_dirY: %f\n", r_dirX, r_dirY);
		
		//As posições guardadas em mapX e mapY serão sempre inteiros. Ou seja, a posição do player no mapa.
		int mapX = (int)p_posX;
		int mapY = (int)p_posY;
		printf("mapX: %d, mapY: %d\n", mapX, mapY);
		
		double sideDistX;
		double sideDistY;
		
		double deltaDistX = (r_dirX == 0) ? 1e30 : fabs(1 / r_dirX);
		double deltaDistY = (r_dirY == 0) ? 1e30 : fabs(1 / r_dirY);
		
		double perpWallDist;
		
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		
		int hit = 0; //was there a wall hit?
		int side = 0; //was a NS or a EW wall hit?
		
		//calculate step and initial sideDist
		if(r_dirX < 0)
		{
			stepX = -1;
			sideDistX = (p_posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - p_posX) * deltaDistX;
		}
		if(r_dirY < 0)
		{
			stepY = -1;
			sideDistY = (p_posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - p_posY) * deltaDistY;
		}

		//perform DDA
		while(hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (cub->map->map[mapX][mapY] == '1')
				hit = 1;
      	}

		printf("sideDistX: %f, sideDistY: %f\n", sideDistX, sideDistY);
        printf("deltaDistX: %f, deltaDistY: %f\n", deltaDistX, deltaDistY);
        printf("r_dirX: %f, r_dirY: %f\n", r_dirX, r_dirY);

		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);


		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;

		if(drawStart < 0)
			drawStart = 0;

		int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;

		if(drawEnd >= SCREEN_HEIGHT)
			drawEnd = SCREEN_HEIGHT - 1;

		int color = 65535;

		if (side == 1)
			color = 33000;

        printf("Drawing line at x: %d, drawStart: %d, drawEnd: %d, color: %d\n", x, drawStart, drawEnd, color);
        printf("perpWallDist: %f\n", perpWallDist);
		printf("lineHeight: %d\n", lineHeight);
		printf("mapX: %d, mapY: %d\n\n", mapX, mapY);


		draw_vertical_line(x, drawStart, drawEnd, color, cub);
		x++;
	}

	mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img, 0, 0);

	return (0);
}

void	ft_mlx_inicialization(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	if (!cub->mlx_ptr)
	{
		ft_clear_cub();
		perror("Error: mlx_init"); //colocar a perror dentro do contexto das nossas msg de erro
		exit (1);
	}
	cub->win = mlx_new_window(cub->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
	if (!cub->win)
	{
		ft_clear_cub();
		perror("Error: mlx_new_window");
		exit (1);
	}
	cub->img = mlx_new_image(cub->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!cub->img)
	{
		ft_clear_cub();
		perror("Error: mlx_new_image");
		exit (1);
	}
}

void	ft_mlx_getdata_and_loop(t_cub *cub)
{
	cub->addr = mlx_get_data_addr(cub->img, &cub->bpp, \
	&cub->line_lenght, &cub->endian);
	if (!cub->addr)
	{	
		ft_clear_cub();
		perror("Error: mlx_get_data_addr");
		exit (1);
	}
	mlx_hook (cub->win, 17, 0, ft_close_x, cub);
	//mlx_key_hook (cub->win, keys, cub); 
	// mlx_expose_hook(cub->win, draw, cub);
	// printf("cub->map->map[0][0]: %c\n", cub->map->map[0][0]);
	// printf("cub->map->map[0][1]: %c\n", cub->map->map[0][1]);
	// printf("cub->map->map[1][0]: %c\n", cub->map->map[1][0]);
	// printf("cub->map->map[1][1]: %c\n", cub->map->map[1][1]);
	draw(cub);
	// printf("cub->map->player->p_x: %d\n", cub->map->player->p_x);
	// printf("cub->map->player->p_y: %d\n", cub->map->player->p_y);
	//mlx_loop_hook(); //tiago indicou o uso (estudar)
	mlx_loop (cub->mlx_ptr);
}




