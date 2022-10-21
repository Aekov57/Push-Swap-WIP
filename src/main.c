/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:12:31 by misimon           #+#    #+#             */
/*   Updated: 2022/10/21 17:30:48 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	int		l;

	l = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			l = -1;
	while (ft_isdigit(*str))
		result = result * 10 + *str++ - '0';
	result *= l;
	return (result);
}

void	check_int(char **tab, int i, int i2)
{
	if (ft_atol(tab[i]) > (long)INT_MAX || ft_atol(tab[i]) < (long)INT_MIN)
		exit(ft_error() + free_tab(tab));
	while (tab[++i2])
	{
		if (ft_atol(tab[i2]) == ft_atol(tab[i]) && i != i2)
			exit(ft_error() + free_tab(tab));
	}
}

int	arg_parsing(char *str, int i)
{
	if (!ft_isdigit(str[i]) && str[i] != ' ' && !ft_issign(str[i]))
		return (ft_error());
	if (ft_issign(str[i]) && (!ft_isdigit(str[i + 1])
			|| ft_isdigit(str[i - 1])))
		return (ft_error());
	return (1);
}

void	one_arg(char **tab, char *arg, int check)
{
	int	i;

	i = -1;
	while (arg[++i])
		if (arg_parsing(arg, i) != 1)
			exit(0);
	tab = ft_split(arg, ' ');
	if (check == 1)
		free(arg);
	if (tab == NULL)
		exit(ft_error());
	i = -1;
	while (tab[++i])
		check_int(tab, i, -1);
	free_tab(tab);
}

char *mult_in_one(char **arg, int ac)
{
	char *str;
	int i;

	i = 0;
	str = calloc(1, sizeof(char));
		while (++i < ac)
		{
				str = ft_strfjoin(str, arg[i]);
			if (i + 1 != ac)
				str = ft_strfjoin(str, " ");
	}
	return (str);
}

void	check_arg(t_list a, char **arg, int ac)
{
	char	**tab;

	(void)a;
	tab = NULL;
	if (ac < 2)
		exit(1);
	one_arg(tab, mult_in_one(arg, ac), 1);
}

int	main(int ac, char **av)
{
	t_list	a;
	t_list	b;
	int		i;

	a.nbr = 0;
	(void)b;
	check_arg(a, av, ac);
	i = 0;
	return (1);
}

// TODO: Vérifier si les arg sont stocker dans 1 seul argv ou dans plusieurs !
// TODO: Mettre les arg une fois convertis dans la liste chainé A !
