
# <p align="center">Push Swap</p>
  
This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for an
optimized data sorting.

## 🧐 Moves    
- RA | RB | RR

> Shift up all elements of stack A (RA), B (RB) or both (RR) by 1. The first element becomes the last one.

>  Example: If stack A contains [3, 2, 1], the RA instruction will transform it into [2, 1, 3].

- RRA | RRB | RRR

> Shift down all elements of stack A (RRA), B (RRB) or both (RRR) by 1. The last element becomes the first one.

>  Example: If stack A contains [3, 2, 1], the RRA instruction will transform it into [1, 3, 2].

- SA | SB | SS

> Swap the first 2 elements at the top of stack A (SA), B (SB) or both (SS) .Do nothing if there is only one or no elements.

>  Example: If stack A contains [3, 2, 1], the SA instruction will transform it into [2, 3, 1].

- PA | PB

> Take the first element at the top of B (PA) or A (PB) and put it at the top of A (PA) or B (PB). Do nothing if the stack is empty.

> Example: If stack A contains [3, 2] and the stack B contains [1, 4], the PA instruction will transform the stack A into [1, 3, 2] and the stack B into[4].

## 🛠️ To compile the project, use the Makefile:

```bash
make push_swap
```

## 🧮 Sorting Algorithm

Push Swap employs a sorting algorithm that combines elements of insertion sort and selection sort techniques. The algorithm operates on two stacks, A and B, and proceeds through several phases to sort the elements efficiently.

### Presort Phase

The sorting begins with the Presort phase, where each element in stack A is indexed. The algorithm then applies a heuristic calculation based on the length of the stack to determine the optimal number of iterations for sorting.

### Sort 3 bigger

When 3 biggers elements left in stack A we sort them with the differents possibility.

### Sorting Phase

After the Presort phase, the algorithm proceeds to the sorting phase. Here, elements are moved from stack B to stack A. If the bottom of stack A was smaller than top of stack B we PA and RA else we push the bigger index left in stack B. Then we check if the bottom A was the next one for RRA.

## 🧑🏻‍💻 Usage

Use the Makefile for compile the project then execute the program with numeric integer argument. The program will display in the stdout a list of action for sort the list.
        
```bash
./push_swap 98 63 78 52 14 -95 654 0 -42
ra
pb
ra
pb
rb
pb
rb
pb
ra
pb
pb
sa
pa
rr
rb
rb
pa
ra
rrb
pa
rra
pa
pa
rra
pa
```
If you want you can run it with a checker 

```bash        
ARG="98 63 78 52 14 -95 654 0 -42" ; ./push_swap $ARG | ./checker $ARG
OK    
```
## 🙇 Author
#### [Juffard Michel](https://github.com/MichJuffard) [(Mjuffard)](https://profile.intra.42.fr/users/mjuffard)


        
