/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:27:12 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/29 16:27:19 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*tfunc_1(void *);
void	*tfunc_2(void *);
typedef struct s_res
{
	bool			fork_free;
	int				value;
	pthread_mutex_t	mutex;
}	t_res;

// args[0] = 1 means fork is free, args[0] = 0 means fork is taken
// args[1] is the value that both threads will increment, it should be protected by the mutex
int	main(void)
{
	pthread_t		thread1;
	pthread_t		thread2;
	t_res			res;

	res.fork_free = true;
	res.value = 0;
	pthread_mutex_init(&(res.mutex), NULL);
	pthread_create(&thread1, NULL, tfunc_1, (void *) &res);
	pthread_create(&thread2, NULL, tfunc_2, (void *) &res);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_mutex_destroy(&(res.mutex));
	printf("Final value: %d\n", res.value);
}

void	*tfunc_1(void *arg)
{
	t_res *res;

	res = (t_res *) arg;
	printf("thread 1: start\n");
	pthread_mutex_lock(&(res->mutex));
	if (res->fork_free)
	{
		res->value++;
		res->fork_free = false;
		printf("thread 1: took the fork, eating\n");
	}
	else
		printf("thread 1: fork is not free\n");
	pthread_mutex_unlock(&(res->mutex));
	sleep(1);
	printf("thread 1: done eating, released the fork\n");
	res->fork_free = true;
	return (NULL);
}

void	*tfunc_2(void *arg)
{
	t_res *res;

	res = (t_res *) arg;
	printf("thread 2: start\n");
	pthread_mutex_lock(&(res->mutex));
	if (res->fork_free)
	{
		res->value++;
		res->fork_free = false;
		printf("thread 2: took the fork\n");
	}
	else
		printf("thread 2: fork is not free\n");
	pthread_mutex_unlock(&(res->mutex));
	return (NULL);
}
