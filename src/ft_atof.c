/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:59:27 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/05 20:53:13 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	is_neg(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

double	res(double res, int comma, int signe)
{
	int	powerof;

	powerof = 1;
	while (comma-- > 0)
		powerof *= 10;
	res = res / powerof;
	return (signe * res);
}
int	count_comma(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[i] == '.')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			count++;
		i++;
	}
	return (count);
}

double	ft_atof(char *str)
{
	double	ret;
	int		i;
	int		signe;
	int		comma;

	comma = 0;
	i = 0;
	ret = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	signe = is_neg(str[i]);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			ret = ret * 10 + str[i] - '0';
		if (str[i] == '.')
			comma = count_comma(&str[i]);
		i++;
	}
	return (res(ret, comma, signe));
}
