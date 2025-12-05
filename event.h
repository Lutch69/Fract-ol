/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:37:28 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/05 22:40:35 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

# define ON_KEYDOWN		2
# define ON_KEYUP		3
# define ON_MOUSEDOWN	4
# define ON_MOUSEUP		5
# define ON_MOUSEMOVE	6
# define ON_DESTROY		17

#ifdef LINUX
	# define KEY_ESC 65307
	# define KEY_LEFT 65361
	# define KEY_RIGHT 65363
	# define KEY_UP 65362
	# define KEY_DOWN 65364
	# define KEY_PLUS 65451
	# define KEY_MINUS 65453
	# define MOUSE_MASK 1L << 6
#endif

#ifdef MACOS
	# define KEY_ESC 53
	# define KEY_LEFT 0
	# define KEY_RIGHT 2
	# define KEY_UP 13
	# define KEY_DOWN 1
	# define KEY_PLUS 126
	# define KEY_MINUS 125
	# define MOUSE_MASK 0
#endif

