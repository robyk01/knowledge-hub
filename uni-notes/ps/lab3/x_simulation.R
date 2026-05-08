# Simulation of a finite random variable
x = c(5, 1, 2, 18, 20)
p = c(0.1, 0.2, 0.5, 0.1, 0.1)
X = function(n, x, p) {
  segm = cumsum(p)
  res = numeric(n)
  
  for (i in 1:n){
    u = runif(1)
    idx = which(segm >= u)[1]
    res[i] = x[idx]
  }
  
  return(list(
    X = matrix(c(x, p), ncol = 2, dimnames = list(NULL, c("x", "p"))),
    Simulation = res
  ))
}

X(10, x, p)
