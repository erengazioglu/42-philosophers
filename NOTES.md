# philosophers | Notes

## Philo (mandatory)

- Implemented `uatoi` for parsing args.

## Ideas

- Create N+1 philosophers where philosopher 0 is the model. 
    - You can then access philosopher 0 each time you need to read the args.
    - `philos[0].eat_count` will give you the win condition.
- Create N forks at the same time as you create philosophers. 
    - This creates forks to the _left_ of each philosopher (philo 1 -> fork 0).
- For simpler stateful actions, set philosopher state and return a `bool`: false if state changed, true if it stays unchanged. So that you can loop as `while (ph_eat(philo) {...}). But what do I even write after the condition?