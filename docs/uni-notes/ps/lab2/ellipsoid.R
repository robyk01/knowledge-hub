# we need to estimate the volume of the ellipsoid
# a, b, c - ellipsoid semiaxes
# n - number of points

ellipsoid <-  function(a, b, c, n) {
  # generate random uniform numbers in the given intervals
  x <- runif(n, -a, a)
  y <- runif(n, -b, b)
  z <- runif(n, -c, c)
  
  # count how many of the n numbers are inside the interval
  # sum function adds boolean values (eg true + false + true = 1 + 0 + 1)
  test <- sum((x^2/a^2 + y^2/b^2 + z^2/c^2) <= 1)
  
  # calc the volume of the box
  vol <- (2*a) * (2*b) * (2*c)
  
  # calc the estimated volume (how much is the ellipsoid volume out of the box volume)
  vol_est <- (test / n) * vol
  
  # real volume of the ellipsoid
  vol_true <- (4/3) * pi * a * b * c
  
  # calc the difference between estimated volume and the real volume (percentage)
  error <- abs(vol_est - vol_true) / vol_true
  
  return(list(Estimare = vol_est, Real = vol_true, Eroare = error))
}

a <- 2
b <- 3
c_vals <- c(5, 6)
n_vals <- c(10000, 20000, 50000)

for (c in c_vals) {
  for (n in n_vals) {
    res <- ellipsoid(a, b, c, n)
    cat("a =", a, "b =", b, "c =", c, "n =", n, "ellipsoid =", paste(res), "\n")
  }
}



