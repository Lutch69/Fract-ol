/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:22:24 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/27 14:10:25 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
}
int	mouse_press(int mousecode, void *param)
{
	(void) param;
	printf ("%d\n", mousecode);

	return(0);
}

int	key_press(int keycode, void *param)
{
	(void)param;
	printf ("%d\n", keycode);
	if (keycode == 65307) // code de la touche ESC
		close_window(param);
	return (0);
}


int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	t_data data;
	set_updata(&data);
	data.x_decal = data.x - data.cx;
	data.y_decal = data.y - data.cy;
	mlx_ptr = mlx_init();// initialiser la connexion avec le systeme graphique
	win_ptr = mlx_new_window(mlx_ptr, data.size_x, data.size_y, "MLX 42"); // creer une fenetre (connexion, largeur, hauteur, titre)
	while(data.y < 150)
	{
		data.x = 0;
		while (data.x < 150)
		{
			if (data.x >= 60 && data.x <= 120)
				mlx_pixel_put(mlx_ptr, win_ptr, data.x, data.y, 0x00FF0000);

			// mettre un pixel (pointeur de la connection, pointeur de la fenetre, coordonnee x et y, couleur)
			data.x++;
		}
		mlx_pixel_put(mlx_ptr, win_ptr, data.x, data.y, 0x0000FFFF);
		y++;
	}
	mlx_key_hook(win_ptr, key_press, NULL); // appliquer une action depuis le clavier (pointeur de la fenetre, (pointeur sur fonction), pointeur (sur structure))
	mlx_mouse_hook(win_ptr, mouse_press, NULL);
	mlx_hook(win_ptr, 17, 0, close_window, NULL);
	mlx_loop(mlx_ptr);// lancer la boucle d'evenement pour garder le programme actif
	return(0);
}

/*Et pour compiler, tu devras lier avec plusieurs bibliothèques :
```
-Lminilibx-linux -lmlx -lXext -lX11 -lm*/
