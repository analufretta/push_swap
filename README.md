*This project has been created as part of the 42 curriculum by ***afretta-***.*

# push_swap

## Description

The **push_swap** project is a sorting algorithm challenge. Its goal is to sort data in a stack (represented as a linked list) with the fewest number of operations, using only two stacks (`a` and `b`) and a limited set of operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`). The project focuses on algorithmic efficiency, optimization, and understanding stack manipulation.

The main objectives are:

- Rank elements in the stack.
- Divide the dataset into chunks to optimize pushing.
- Push and rotate elements between stacks to sort them using the minimum number of moves.
- Calculate the cost of operations to determine the most efficient sequence.

## Instructions

### Compilation

```bash
make
```

### Execution

To sort a ser of numbers:

```bash
./push_swap [numbers...]
```
Example:

```bash
./push_swap 3 2 5 1 4
```
This will output the sequence of operations needed to sort the numbers in ascending order.

### Testing

You can test your program with random numbers:

```bash
ruby -e "puts (1..100).to_a.shuffle.join(' ')" > 100numbers.txt
./push_swap $(cat 100numbers.txt)
```

```bash
ruby -e "puts Array.new(500) { rand(-2_147_483_648..2_147_483_647) }.join(' ')" > 500numbers.txt
./push_swap $(cat 500numbers.txt)
```
You can could the number of operations:

```bash
./push_swap $(cat 500numbers.txt) | wc -l
```

You can check the result with the checker programm:

```bash
./push_swap $(cat ./tests/500numbers.txt) | ./checker/checker_Mac $(cat ./tests/500numbers.txt)
```

### Resources

42 Push_swap Subject

Stack and linked list tutorials:

https://www.youtube.com/watch?v=NobHlGUjV3g
https://www.geeksforgeeks.org/stack-data-structure/

Sorting algorithm references:

https://www.youtube.com/watch?v=Y95a-8oNqps
https://medium.com/@ayogun/push-swap-c1f5d2d41e97


### AI Assistance

AI (ChatGPT) was used to:

- Clarify cost calculations for moves between stacks.

- Clarify stack manipulation logic.

No code was copied; all AI usage was for guidance and explanation purposes only.

### Technical Choices

**Data structure**: Doubly-linked list to represent stacks for efficient rotations and push operations.

**Algorithm**: Chunk-based sorting with cost analysis to minimize total operations.

**Language**: C
