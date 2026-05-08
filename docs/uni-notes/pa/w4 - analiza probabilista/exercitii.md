1. Assuming the vector v contains a random permutation of numbers from 1 to n, and assuming
that each possible permutation is equiprobable (given as input with the same probability),
what is the average execution time of the algorithm for input data of size n? Hint: Compute
the average number of executions of the inner for loop.

max = v[0];
sum = 0;
for (i = 0; i < n; ++i) {
    if (v[i] > max) {
        max = v[i];
        for (j = 0; j < n; ++j) { // bucla for interioara
            sum = sum + 1; // (inner for loop)
        }
    }
}
return sum;

For a random permutation, the probability that v[i] is a maximum: 1/i+1
The expected number of times for the inner loop is H(n): harmonic series which is asimptotically close to ln n. To calculate the total number we multiply by the main loop