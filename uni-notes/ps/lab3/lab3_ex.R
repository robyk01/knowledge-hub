# Generating random integers
x = sample(300, 1) # generate a random number from 1 to 300
x = sample(200:250, 5) # generate five random numbers from 200 to 250

x = sample(5, 6, replace=T) # generate with repetition (default is false)

x = c(2.1, 3.2, 2.3, 2.5, 3.1, 2.9, 2.6, 2.2, 3.3)
sample(x, 6) # generate from an existing vector

sample(10) # generate random permutation


# Generate random uniform numbers
runif(10, 2, 4.5) # ten uniform values between 2 and 4.5
runif(4, 0, 1)


# Random algorithms
# Monte Carlo
x = c(1, 3, 1, 4, 12, 7)
M = matrix(x, 3, 2) # creates a 3x2 matrix
n = nrow(M) # number of rows
r = matrix( ,nrow = n, ncol = 1)
r = sample(0:1, n, replace = T)
r
