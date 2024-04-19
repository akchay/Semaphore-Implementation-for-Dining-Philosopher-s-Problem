Dijkstra's solution using semaphores: Assign a semaphore to each chopstick, representing its availability. Philosophers must acquire both chopsticks by locking their corresponding semaphores. If a philosopher cannot acquire both chopsticks, they release the acquired chopstick and wait before trying again.


<img width="665" alt="Screenshot 2024-04-18 at 8 27 32 PM" src="https://github.com/akchay/Semaphore-Implementation-for-Dining-Philosopher-s-Problem/assets/6744434/ac6fcc8d-e1ad-45d3-a966-9154f491f2d6">
