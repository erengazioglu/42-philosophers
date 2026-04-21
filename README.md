# minishell

_This project has been created as part of the 42 curriculum by egaziogl._

## Description

_(TBD)_

### Requirements

> libft is not allowed in this project.

Program execution:
`./philo <philosopher_count> <time_to_die> <time_to_eat> <time_to_sleep> [meals_required]`, where:  
- `<philosopher_count>`: number of philosophers (= number of forks).
- `<time_to_die>`: countdown until the philosopher dies because of not having eaten for too long (in milliseconds).
- `<time_to_eat>`: how long it takes for one philosopher to eat (in milliseconds).
- `<time_to_sleep>`: how long the philosopher sleeps.
- `[meals_required]`: optional, number of times each and all philosophers must have eaten before the simulation stops.

External functions allowed:  
- memory (`memset, malloc, free`),
- time functions (`usleep, gettimeofday`),
- pthread creation (`pthread_create, pthread_detach, pthread_join`),
- pthread mutexes (`pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock`),
- printf & write.

Mandatory requirements:  
- Each philosopher is a separate _thread._
- _(more TBD)_

Bonus requirements:  
- _(TBD)_

## Instructions

_(no content yet.)_

## Resources

- **man pages** for all the external functions listed above, in the [requirements](#requirements) section.
- [The Linux Programming Interface](https://man7.org/tlpi/) by Michael Kerrisk (book).
- **these youtube videos:**
    - [Introduction to Threads (pthreads) | Portfolio Courses](https://www.youtube.com/watch?v=ldJ8WGZVXZk)
    - [Mutex Introduction (pthreads) | Portfolio Courses](https://www.youtube.com/watch?v=f_uWOWViYc0)