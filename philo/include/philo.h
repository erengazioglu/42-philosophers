/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:38:22 by egaziogl          #+#    #+#             */
/*   Updated: 2026/05/02 18:27:57 by egaziogl         ###   ########.fr       */
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

typedef enum e_state
{
	EXIT,
	INIT,
	THINK,
	EAT,
	SLEEP,
	DIE
}	t_state;

typedef	struct s_cd
{
	int	die;
	int	eat;
	int	sleep;
}	t_cd;

typedef struct s_config
{
	t_cd	timers;
	bool	*forks;
	bool	*end_flag;
	int		eat_target;
	long	start_time;
}	t_conf;

typedef struct s_philo
{
	int		nbr;
	int		eat_count;
	t_state	state;
	t_conf	config;
	t_cd	timers;
	bool	*end_simulation;
}	t_philo;


// ft_uatoi.c

int		ft_uatoi(const char *str);

// util.c

bool	parse_args(int argc, char **argv, int *arr);
long	current_time_ms(void);
void	print_msg(t_philo *philo, t_state msg);

// philo.c

t_state switch_state(t_philo *philo, t_state new_state);
t_philo *new_philo(int n, t_cd settings, long start_time, bool *end_flag);

// philo_actions.c

t_state	ph_eat(t_philo *philo, bool *forks);
t_state	ph_sleep(t_philo *philo);
t_state	ph_think(t_philo *philo);

// philo_forks.c

bool	grab_forks(t_philo *philo, bool *forks);
void	release_forks(t_philo *philo, bool *forks);

#endif