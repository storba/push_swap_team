*This project has been created as part of the 42 curriculum by svpanfil <svpanfil@student.codam.nl>, yelkorni <yelkorni@student.42.fr>*

---

## Description

`push_swap` is an algorithmic sorting project where a list of integers must be sorted in ascending order using only a fixed set of stack operations on two stacks: `a` and `b`.

The program prints a sequence of instructions (`sa`, `pb`, `ra`, etc.) to `stdout`.  
The objective is not only to sort correctly, but to do it with as few operations as possible.

This implementation includes four strategies required by the subject:

- **Simple**: baseline `O(n^2)` strategy.
- **Medium**: `O(n * sqrt(n))` strategy.
- **Complex**: `O(n log n)` strategy.
- **Adaptive**: dynamic strategy selected using the disorder metric (default mode).

The project also includes `checker` (bonus) to validate operation streams.

---

## Rules And Allowed Operations

Initial state:

- Stack `a` contains unique signed integers.
- Stack `b` is empty.
- Goal: sort stack `a` in ascending order.

Allowed operations:

- `sa`, `sb`, `ss` - swap top elements
- `pa`, `pb` - push top element between stacks
- `ra`, `rb`, `rr` - rotate up
- `rra`, `rrb`, `rrr` - reverse rotate down

In case of invalid input, the program prints `Error` followed by `\n` to `stderr`.

---

## Instructions

### Build

```bash
make
```

### Rebuild from scratch

```bash
make re
```

### Build checker (bonus)

```bash
make bonus
```

### Cleanup

```bash
make clean
make fclean
```

### Run push_swap

```bash
./push_swap 2 1 3 6 5 8
```

### Strategy selector

```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

If no selector is passed, `--adaptive` is used.

### Benchmark mode

```bash
./push_swap --bench --adaptive 4 67 3 87 23
```

`--bench` prints metrics to `stderr` (disorder, chosen strategy, complexity label, total ops, per-op counters).

### Use checker

On Linux:

```bash
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_linux $ARG
```

On macOS (after `make bonus`):

```bash
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker $ARG
```

---

## Algorithm Design And Rationale

### 1) Disorder metric (mandatory)

Before sorting, the program computes input disorder in `[0, 1]` based on inverted pairs:

- `0.0` means already sorted.
- `1.0` means maximally disordered.

Conceptually:

1. For all pairs `(i, j)` where `i < j`,
2. count inversions `a[i] > a[j]`,
3. divide by total number of pairs.

This gives a normalized measure of how far the input is from sorted order.

### 2) Simple strategy - `O(n^2)`

A baseline approach intended for small inputs and clarity:

- repeatedly identifies useful local moves,
- uses basic push/rotate/swap combinations,
- prioritizes correctness with predictable behavior.

Operation growth is quadratic in the Push Swap model.

### 3) Medium strategy - `O(n * sqrt(n))`

Chunk/range-based logic:

- split values into roughly `sqrt(n)` groups,
- push and reassemble by ranges,
- reduce unnecessary rotations by structured partitioning.

This provides better scaling than simple quadratic behavior for medium-sized inputs.

### 4) Complex strategy - `O(n log n)`

Higher-performance path for highly disordered or larger inputs:

- optimized push/rotate scheduling,
- cost-based move selection,
- global minimization of operation count per insertion phase.

This strategy targets logarithmic-layered behavior in operation generation.

### 5) Adaptive strategy (default)

Adaptive mode selects internal behavior from measured disorder:

- **Low disorder (`d < 0.2`)**: near-linear behavior target (`O(n)`).
- **Medium disorder (`0.2 <= d < 0.5`)**: medium strategy target (`O(n * sqrt(n))`).
- **High disorder (`d >= 0.5`)**: complex strategy target (`O(n log n)`).

Why these thresholds:

- `0.2` separates almost-sorted inputs where local fixes are efficient.
- `0.5` marks strongly mixed inputs where global optimization is typically cheaper.

Space complexity remains bounded by the two-stack model and bookkeeping structures.

---

## Performance Targets (Subject)

For random inputs, expected quality tiers are:

- **100 numbers**
  - pass: `< 2000`
  - good: `< 1500`
  - excellent: `< 700`
- **500 numbers**
  - pass: `< 12000`
  - good: `< 8000`
  - excellent: `< 5500`

---

## Resources

- [42 push_swap subject (project PDF in repository)](push_swap.pdf)
- [Big-O notation overview](https://en.wikipedia.org/wiki/Big_O_notation)
- [Stack data structure reference](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Sorting algorithm reference](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [C language reference (cppreference)](https://en.cppreference.com/w/c)

### AI usage

AI (Cursor assistant) was used for:

- improving project documentation structure and wording;
- clarifying complexity terminology and subject requirement interpretation;
- checking readability/consistency of explanations.

AI was not used to blindly generate mandatory C implementation logic without review.
