/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cases_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:43:35 by lbellmas          #+#    #+#             */
/*   Updated: 2024/11/26 16:41:14 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include "../libft/libft.h"

int	ft_plus(char **str)
{
	int	p;

	p = 0;
	while (str[p])
		p++;
	str[p] = ft_strdup("+");
	ft_swap(&str[p], &str[p - 1]);
	return (1);
}

int	ft_space(char **str)
{
	int	p;

	p = 0;
	while (str[p])
		p++;
	str[p] = ft_strdup(" ");
	ft_swap(&str[p], &str[p - 1]);
	return (1);
}

int	ft_dot(int len, char **str, char fmt)
{
	int	p;

	p = 0;
	while (str[p])
		p++;
	if ((fmt == 'd' || fmt == 'i') && str[p - 1][0] == '-')
	{
		str[p] = (char *)malloc(len + 1);
		if (!str[p])
			return (-1);
		str[p][0] = '-';
		ft_memset(str[p] + 1, '0', len);
		ft_strlcpy(str[p - 1], str[p - 1] + 1, ft_strlen(str[p - 1]));
	}
	else
	{
		str[p] = (char *)malloc(len + 1);
		ft_memset(str[p], '0', len);
	}
	str[p][len] = '\0';
	ft_swap(&str[p], &str[p - 1]);
	return (1);
}

int	ft_minus(int len, char **str)
{
	int	p;

	p = 0;
	while (str[p])
		p++;
	str[p] = (char *)malloc(len + 1);
	if (!str[p])
		return (-1);
	ft_memset(str[p], ' ', len);
	str[p][len] = '\0';
	return (1);
}

int	ft_num(int len, char **str)
{
	int	p;

	p = 0;
	while (str[p])
		p++;
	str[p] = (char *)malloc(len + 1);
	if (!str[p])
		return (-1);
	ft_memset(str[p], ' ', len);
	str[p][len] = '\0';
	ft_swap(&str[p], &str[p - 1]);
	return (1);
}