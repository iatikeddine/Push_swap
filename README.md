*This project has been created as part of the 42 curriculum by iatikedd.*

# push_swap

## Description

**push_swap** is an algorithmic project whose goal is to sort a stack of integers using a limited set of operations and the smallest possible number of moves.

The program receives a list of integers as input and must output a sequence of valid operations that sorts the numbers in ascending order using two stacks:
- **Stack A** (initially filled)
- **Stack B** (initially empty)

Only a restricted set of operations (swap, push, rotate, reverse rotate) is allowed.

To achieve **100% validation**, this project uses a **chunk-based sorting strategy** optimized for both correctness and performance.

### Algorithm Overview

1. **Parsing & Validation**
   - The program parses all input arguments.
   - It checks for:
     - valid integers
     - integer overflow
     - empty or invalid arguments
     - duplicate values
   - If any error is detected, the program exits with `Error`.

2. **Chunk Strategy**
   - A temporary sorted array is created from Stack A.
   - This array is used as a reference to divide the values into **chunks**.
   - Values are pushed from Stack A to Stack B chunk by chunk.

3. **Pushing A → B**
   - If the top of Stack A belongs to the current chunk → it is pushed to Stack B.
   - Otherwise, Stack A is rotated (`ra`).
   - When a value is pushed to Stack B:
     - If it is lower than the middle value of the chunk, Stack B is rotated.
     - This keeps larger values closer to the top of Stack B.
   
   This approach was chosen after experimentation:
   - Searching for the *nearest* chunk value reduced rotations in A, but made Stack B very disorganized.
   - Simply rotating A until a chunk value appears proved more stable and significantly reduced the cost of pushing values back to A.

4. **Pushing B → A**
   - Once Stack A is empty, values are pushed back from Stack B to Stack A.
   - The algorithm looks for the **maximum** and **second maximum** values in Stack B.
   - The value closest to the top is rotated into position and pushed to Stack A.
   - If the second maximum is pushed first, the maximum is pushed immediately after and Stack A is swapped to maintain order.
   - This process continues until Stack B is empty.

5. **Final Result**
   - Stack A ends fully sorted in ascending order.
   - Stack B is empty.

---

## Instructions

### Compilation

To compile the main program:

```bash
make
```

This will create the `push_swap` executable.

To compile with the bonus checker:

```bash
make bonus
```

### Execution

Run the program with a list of integers:

```bash
./push_swap 4 67 3 87 23
```

You can also pass arguments as a single quoted string:

```bash
./push_swap "4 67 3 87 23"
```

The program will output the sequence of operations needed to sort the stack.

### Using the Checker (Bonus)

To verify if the operations correctly sort the stack:

```bash
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
```

The checker will output:
- `OK` if the stack is sorted correctly
- `KO` if the stack is not sorted or contains errors
- `Error` if invalid input is provided

### Available Operations

- `sa` - swap the first two elements of stack A
- `sb` - swap the first two elements of stack B
- `ss` - `sa` and `sb` at the same time
- `pa` - push the first element of stack B to stack A
- `pb` - push the first element of stack A to stack B
- `ra` - rotate stack A up by one
- `rb` - rotate stack B up by one
- `rr` - `ra` and `rb` at the same time
- `rra` - reverse rotate stack A
- `rrb` - reverse rotate stack B
- `rrr` - `rra` and `rrb` at the same time

---

## Resources

This project was developed using the following resources:

### Documentation
- [Introduction to Stack Data Structure - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/introduction-to-stack-data-structure-and-algorithm-tutorials/) - Understanding stack data structure fundamentals, operations, and implementation

### Tutorials
- **YouTube tutorials** - Various video tutorials explaining stack operations, sorting algorithms, and the push_swap problem approach
- **CS50 Data Structures module** - Harvard's CS50 course module on data structures, covering stack implementation and memory management

---

## AI Usage Declaration

**AI was used for:**
- Understanding and interpreting the project subject requirements
- Identifying what should be considered as errors according to the subject specifications
- Clarifying edge cases
- Ensuring proper markdown syntax and section organization for README file