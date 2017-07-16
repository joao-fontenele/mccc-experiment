## MCCC

### What is this

The main program prints a csv like file. Each line represents an experiment,
using one of the sorting methods, and one kind of array.

The numbered columns contain the runtime for a single run of the sort method in
the generated array, and the last column contain the average time of all the
repetitions.

Sorting methods:
- quicksort
- random pivot quicksort
- bubblesort

Array types:
- random
- ordered
- ordered in reverse
- all elements repeated

### Compiling

```
make
```

### Running

Positional command line arguments are:

- repetitions: amount of times each method is run, to take the average.
- array sizes: a variable amount of array sizes

```
./main <repetitions> <...array sizes>
./main 30 500
```

One possible output for the command above would be:

```csv
sort,type,n,avg
quicksort,random,500,0.000059
quicksort,ordered,500,0.000597
quicksort,reversed,500,0.000963
quicksort,repeated,500,0.000563
quicksortRandom,random,500,0.000667
quicksortRandom,ordered,500,0.000586
quicksortRandom,reversed,500,0.000725
quicksortRandom,repeated,500,0.001428
bubblesort,random,500,0.001558
bubblesort,ordered,500,0.000002
bubblesort,reversed,500,0.001851
bubblesort,repeated,500,0.000002
```
