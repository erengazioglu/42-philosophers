# philosophers | Notes

## Philo (mandatory)

- Implemented `uatoi` for parsing args.

## Ideas

- Create N+1 philosophers where philosopher 0 is the model. 
    - You can then access philosopher 0 each time you need to read the args.
    - `philos[0].eat_count` will give you the win condition.
- Create N forks at the same time as you create philosophers. 
    - This creates forks to the _left_ of each philosopher (philo 1 -> fork 0).
