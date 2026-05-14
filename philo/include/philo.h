/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:38:22 by egaziogl          #+#    #+#             */
/*   Updated: 2026/05/15 01:08:54 by egaziogl         ###   ########.fr       */
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
	int		target;
	long	start_time;
}	t_conf;

/**
 * @brief Philosopher struct, containing all information about 
 * a single philosopher.
 * @param n		Unique philosopher number (1-indexed).
 * @param ate	Number of times the philosopher has eaten.
 * @param state	Current state of the philosopher (THINK, EAT, SLEEP, DIE).
 * @param timers	Struct containing the philosopher's current die, eat, and sleep timers.
 * @param config	Pointer to shared configuration struct.
 * @param sim_end	Pointer to shared end simulation flag.
 */
typedef struct s_philo
{
	int		n;
	int		ate;
	t_state	state;
	t_cd	timers;
	t_conf	*config;
	bool	*sim_fin;
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