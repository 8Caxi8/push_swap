# Push_swap

*This project has been created as part of the 42 curriculum by dansimoe*

## Overview

**push_swap** is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations and two stacks.

## Description

The program receives a list of integers as command-line arguments and stores them in **stack_a**, with the first argument placed at the top of the stack. A second stack, **stack_b**, starts empty.

The objective is to sort **stack_a** in ascending order using only the allowed operations. At the end of the program, **stack_b** must be empty.

The program outputs to standard output the sequence of operations used to sort the stack. 

## Allowed Operations

### Rotate

- **ra**: rotate stack_a upward
- **rb**: rotate stack_b upward
- **rr**: perform `ra` and `rb` simultaniously

### Reverse Rotate

- **rra**: reverse rotate stack_a
- **rrb**: reverse rotate stack_b
- **rrr**: perform `rra` and `rrb` simultaniously

### Swap

- **sa**: swap the first two elements of stack_a
- **sb**: swap the first two elements of stack_b
- **ss**: perform `sa` and `sb` simultaniously

### Push

- **pa**: push the top element of stack_b onto stack_a
- **pb**: push the top element of stack_a onto stack_b

## Instructions

To make the push_swap binary just run `make` or `make all` or `make push_swap`. to execute the program, just run the program `push_swap` followed by the listed numbers:

```bash
$>./push_swap 5 1 2 4 3
```

The program can also receive a string, or both:

```bash
$>./push_swap "5 1 2 4 3" or $>./push_swap "5 1" 2 "4 3"
```

You can also run the program with random `n` numbers like this:

```bash
$>ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG
```
- -i 1-1000 -> bounded range
- -n 100 -> exactly 100 numbers

### Constraints

- Only the listed operations are allowed
- Input must contain valid integers
- Duplicate values are not permitted
- Values must fit within the 32-bit signed integer range

If any of this are violated, the program will display `Error` to the standard error output and exit.

## Bonus

The bonus part consists of implementing a **checker** program that validates the output of `push_swap`.

The `checker` program receives a list of integers as command-line arguments, in the same format as `push_swap`. It then reads a sequence of operations from **standard input** until the input ends.

If the given operations correctly sort the list in ascending order and leave **stack_b** empty, the program displays `OK` on **standard output**. Otherwise, it displays `KO`.

Again if any of the constraints are violated, the program will display `Error` to the standard error output and exit.

### Usage

It can be run as 

```bash
$>./checker "5 1 2 4 3"
rra
rra
sa
rra
rra
OK
```

Dont forget to press **CTRL + D** to signal the end of imput.

### Using push_swap with checker

You can also pipe the `push_swap` directly into `checker` like this:

```bash
$>ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
```

## Resources

The following pages where used to understand the algorithms to adopt

1. [turk algorithm description](https://www.marcioflavio.com/push_swap-the-algorithmic-challenge-of-sorting/)
2. [geeks lis](https://www.geeksforgeeks.org/dsa/longest-increasing-subsequence-dp-3/)
3. [youtube lis](https://www.youtube.com/watch?v=fV-TF4OvZpk)
4. [youtube bfs](https://www.youtube.com/watch?v=HZ5YTanv5QE)
5. [bfs algorithm](https://www.codecademy.com/article/breadth-first-search-bfs-algorithm)

AI was also used to help me debug, and help me to understand how could I combine the diferent algorithms implemented to calculate the best scenario.