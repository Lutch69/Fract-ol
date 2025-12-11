/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:37:28 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/11 21:06:56 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define ON_KEYDOWN		2
# define ON_KEYUP		3
# define ON_MOUSEDOWN	4
# define ON_MOUSEUP		5
# define ON_MOUSEMOVE	6
# define ON_EXPOSE		12
# define ON_DESTROY		17

#ifdef LINUX
	# define KEY_ESC 65307
	# define KEY_LEFT 65361
	# define KEY_RIGHT 65363
	# define KEY_UP 65362
	# define KEY_DOWN 65364
	# define KEY_W 119
	# define KEY_S 115
	# define KEY_PRESS 2
	# define KEY_SPACE 32
	# define KEY_R 114
	# define KEY_P
	# define KEY_MIN 45
	# define KEY_PLUS 61
	# define KEY_PRESSMASK 1L << 0
	# define BUTTON_PRESS_MASK 1L << 2
	# define BUTTON_RELEASE_MASK 1L << 3
	# define MOUSE_MASK 1L << 6
#endif

#ifdef MACOS
	# define KEY_ESC 53
	# define KEY_LEFT 123
	# define KEY_RIGHT 124
	# define KEY_UP 126
	# define KEY_DOWN 125
	# define KEY_PLUS 18
	# define KEY_MIN 44
	# define KEY_SPACE 49
	# define KEY_R 15
	# define KEY_PRESS 2
	# define KEY_W 13
	# define KEY_S 1
	# define KEY_P 35
	# define KEY_PRESSMASK 0
	# define BUTTON_PRESS_MASK 0
	# define BUTTON_RELEASE_MASK 0
	# define MOUSE_MASK 0
#endif

