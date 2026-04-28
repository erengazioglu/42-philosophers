/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:56:47 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/28 17:25:27 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*t1func(void *);
void	*t2func(void *);
void	*t3func(void *);

int	main(void)
{
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;

	pthread_create(&thread1, NULL, t1func, NULL);
	pthread_create(&thread2, NULL, t2func, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_create(&thread3, NULL, t3func, NULL);
	pthread_join(thread3, NULL);
	return (0);
}

void	*t1func(void *args)
{
	(void) args;
	sleep(1);
	printf("Hello from thread 1!\n");
	return (NULL);
}

void	*t2func(void *args)
{
	(void) args;
	printf("Hello from thread 2!\n");
	sleep(1);
	return (NULL);
}

void	*t3func(void *args)
{
	(void) args;
	sleep(1);
	printf("Hello from thread 3!\n");
	return (NULL);
}