*This project has been created as part of the 42 curriculum by nateremi.*
# Push_swap | 42 Algorithmic Project

## Description

**Push_swap** is a project from 42 School focused on sorting a list of integers using **two stacks (A and B)** and a strictly limited set of operations.

The goal is not just to sort the numbers, but to do it with the **minimum number of operations**, which makes this project primarily about **algorithm optimization** rather than basic sorting.

This project covers:
- data structures (linked lists),
- algorithm optimization,
- cost evaluation strategies,
- robust input parsing and error handling.

The implemented solution follows a **cost-based greedy approach**, where each move is evaluated and the most efficient one is selected at every step.

---

## Instructions

### How It Works

The implementation follows a **cost-based greedy approach** (often referred to as the “Turk Algorithm”).  
In practice, it works by always selecting the **cheapest possible move** at each step.

---

### General Strategy

1. **Initialization**
   - Parse arguments using `ft_split` from **libft** library
   - Convert safely to integers using `safe_atoi` (with overflow protection)
   - Check for duplicates
   - Build stack A as a linked list

2. **Base Cases**
   - 2 numbers → `sa`
   - 3 numbers → `sort_three`

3. **Main Algorithm**
   - Move elements from A to B based on minimal cost
   - Sort the remaining 3 elements in A
   - Move everything back from B to A
   - Final rotation to align the stack

---

### Core Algorithm Details

#### 1. Push from A to B (Cost Optimization)

For each element in stack A:

- A **target node** in stack B is determined:
  - the closest smaller value
  - if none exists → the maximum value in B

- The **push cost** is calculated:
  - rotations needed in A
  - + rotations needed in B

- Additional factors:
  - element position (`index`)
  - whether it is above or below the median (`above_median`)

The node with the **lowest total cost** is selected and moved.

---

#### 2. Rotation Optimization

If:
- the node in A and its target in B are both above the median  
  → use `rr`
- both are below the median  
  → use `rrr`

This reduces the total number of operations by combining rotations.

---

#### 3. Push Back from B to A

For each element in stack B:

- Find its **target node** in A:
  - closest larger value
  - if none exists → the minimum value in A

- Rotate A to the correct position
- Execute `pa`

---

#### 4. Final Adjustment

After all elements are back in A:

- The stack is sorted but may be rotated
- Find the minimum value
- Rotate (`ra` or `rra`) until it is at the top

---

### Data Structure

```c
typedef struct s_node
{
    int             value;
    int             index;
    int             push_cost;
    int             above_median;
    int             cheapest;
    struct s_node   *target_node;
    struct s_node   *next;
} t_node;
```

### Key Fields

- `index` — position in the stack  
- `above_median` — used for rotation optimization  
- `push_cost` — total cost to move the node  
- `target_node` — destination position  
- `cheapest` — marks the optimal node  

---

### Instruction Set

| Command | Description |
|--------|------------|
| `sa` | swap A |
| `sb` | swap B |
| `ss` | sa + sb |
| `pa` | push B → A |
| `pb` | push A → B |
| `ra` | rotate A |
| `rb` | rotate B |
| `rr` | ra + rb |
| `rra` | reverse rotate A |
| `rrb` | reverse rotate B |
| `rrr` | rra + rrb |

---

### Input Handling & Validation

The program handles:

- ✅ multiple arguments and string input  
- ✅ spaces and signs (`+`, `-`)  
- ✅ integer overflow (`INT_MAX`, `INT_MIN`)  
- ❌ non-numeric values  
- ❌ duplicate numbers  

On error:
```bash
Error
```
(Output is written to `stderr`, with no memory leaks.)

---

### Usage
#### Compilation
```bash
make re
```

#### Run
```bash
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
```

#### Check correctness
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

### Project Structure
```text
.
├── src/
│   ├── push_swap.c        # main algorithm
│   ├── init_stack.c       # parsing and initialization
    ├── push_swap.h
│   ├── utils.c            # helper functions
    ├── commands
        ├── pa_pb.c
│       ├── ra_rb_rr.c
│       ├── rra_rrb_rrr.c
│       ├── sa_sb_ss.c│
├── main.c
├── Makefile
└── libft/
```

### Key Features

* Cost-based greedy algorithm
* Rotation optimization using `rr` / `rrr`
* Safe parsing (`safe_atoi`)
* Memory-safe implementation (no leaks)
* Linked list-based stacks
* Focus on minimizing operations

> **Note** > Although commonly referred to as the Turk Algorithm, this approach is essentially:  
> **a greedy strategy combined with cost heuristics**.  
> 
> This means:  
> * It does not guarantee a globally optimal solution.  
> * But provides strong practical performance, sufficient for achieving top scores in the project.   
---

## Resources
### Algorithm & Concepts
 - 42 Subject: Push_swap
 - "Sorting Algorithms" – GeeksforGeeks
 - "Greedy Algorithms" – MIT OpenCourseWare
 - Stack and linked list documentation (C)

### Implementation References
 - Manual pages (`man malloc`, `man write`)
 - 42 libft project

### AI Usage

AI was used as a support tool, not as a source of full solutions.

Specifically:
 - improving and restructuring the README documentation
 - clarifying algorithm explanations
 - reviewing code structure and readability
The core algorithm design, implementation, and debugging were done independently.
