# Philosophers Project

## Description
This is a project for the school 42. The goal of this project is to implement a simulation of the dining philosophers problem using threads and synchronization.

### How to compile library:
* `make` - to compile C files - create object files and library libft.a<br/>
* `make clean` - to remove object files<br/>
* `make fclean` - clean and remove libft.a file<br/>
* `make re` - recompile the library<br/>

## Usage
To run the program, simply execute the binary with the following arguments:
* `./philo 21 210 21 20 ` - to execute programe<br/>

```shell
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```


Here is a brief explanation of each argument:

- `<number_of_philosophers>`: the number of philosophers that will be seated at the table.
- `<time_to_die>`: the maximum time (in milliseconds) a philosopher can go without eating before dying.
- `<time_to_eat>`: the time (in milliseconds) it takes for a philosopher to eat.
- `<time_to_sleep>`: the time (in milliseconds) it takes for a philosopher to sleep.
- `[number_of_times_each_philosopher_must_eat]`: (optional) the number of times each philosopher must eat before the simulation ends.
