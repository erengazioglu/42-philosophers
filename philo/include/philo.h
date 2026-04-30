/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:38:22 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/29 21:19:37 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum e_msg
{
	TAKE_FORKS = 1,
	EAT,
	SLEEP,
	THINK,
	DIE
}	t_msg;

typedef	struct s_cd
{
	int	die;
	int	eat;
	int	sleep;
}	t_cd;

typedef struct s_philo
{
	int		nbr;
	t_cd	cooldowns;
	int		eat_count;
	bool	is_thinking;
}	t_philo;


// ft_uatoi.c

int		ft_uatoi(const char *str);

// util.c

bool	parse_args(int argc, char **argv, int *arr);
long	current_time_ms(void);
void	print_msg(int nbr, t_msg msg, long start_time);

#endif