/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:38:22 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/30 11:50:17 by egaziogl         ###   ########.fr       */
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

typedef enum e_result
{
	DEATH,
	CONTINUE,
	BREAK,
	EXIT
}	t_result;

typedef	struct s_cd
{
	int	die;
	int	eat;
	int	sleep;
}	t_cd;

typedef struct s_philo
{
	long	start_time;
	int		nbr;
	int		eat_count;
	t_cd	settings;
	t_cd	timers;
	bool	is_thinking;
	bool	*end_simulation;
}	t_philo;


// ft_uatoi.c

int		ft_uatoi(const char *str);

// util.c

bool	parse_args(int argc, char **argv, int *arr);
long	current_time_ms(void);
void	print_msg(t_philo *philo, t_msg msg);

// philo_actions.c

t_result	ph_eat(t_philo *philo);
t_result	ph_sleep(t_philo *philo);
t_result	ph_think(t_philo *philo);

// philo_forks.c

bool	grab_forks(t_philo *philo, bool *forks);
void	release_forks(t_philo *philo, bool *forks);

#endif