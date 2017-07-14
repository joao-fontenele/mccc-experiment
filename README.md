## MCCC

### What is this

The main program prints a csv like file. Each line represents an experiment,
using one of the sorting methods, and one kind of array.

The numbered columns contain the runtime for a single run of the sort method in
the generated array, and the last column contain the average time of all the
repetitions.

Sorting methods:
- quicksort
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

- array size: size of the array generated for each of the sorting methods.
- repetitions: amount of times each method is run, to take the average.

```
./main <array size> <repetitions>
./main 500 5
```

One possible output for the command above would be:

```csv
sort,type,n,0,1,2,avg
quicksort,random,500,0.000180,0.001388,0.000998,0.000855
quicksort,ordered,500,0.000600,0.000603,0.000605,0.000603
quicksort,reversed,500,0.000976,0.000600,0.000582,0.000719
quicksort,repeated,500,0.000540,0.000545,0.000542,0.000542
bubblesort,random,500,0.001516,0.000002,0.000002,0.000507
bubblesort,ordered,500,0.000002,0.000002,0.000002,0.000002
bubblesort,reversed,500,0.001865,0.000002,0.000002,0.000623
bubblesort,repeated,500,0.000002,0.000003,0.000002,0.000002
```
