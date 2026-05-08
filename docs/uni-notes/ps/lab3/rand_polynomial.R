f <- function(x) { 1 + 2*x }
g <- function(x) { 3 + 4*x }
h <- function(x) { 3 + 10*x + 8*x^2}

rand_polynomial = function(f, g, h, n) {
  p = sample(1:(3*n), size=1)
  if (f(p) * g(p) == h(p)) {
    return(T)
  } else {
    return(F)
  }
}

n = 1
rand_polynomial(f, g, h, n)

amplified = function(f, g, h, n, iterations=30) {
  for (i in 1:iterations){
    if (rand_polynomial(f, g, h, n) == F) {
      return(F)
    }
  }
  
  return(T)
}

f1 = function(x) { x + 1 }
g1 = function(x) { x - 1 }
h1 = function(x) { x^2 - 1 }
print(amplified(f1, g1, h1, n)) # true

h2 = function(x) { x^2 + 1 }
print(amplified(f1, g1, h2, n)) # false