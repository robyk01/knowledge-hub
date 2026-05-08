# a)
# we need to estimate the integral and compare with the real value

f <- function(x) {sin(x) / x}

a <- 10
n <- 50000

# chose n random values between 0 and a to find the area under the curve of the integral
x <- runif(n, min=0, max=a)

y <- f(x)

# mean - average height of the function
# a - total width of the interval
# by multiplying height with width we get the area of a rectanglw
int_est <- mean(y) * a

true_val <- pi / 2

error <- abs(true_val - int_est)

cat("Estimation:", int_est, "\n")
cat("Real value:", true_val, "\n")
cat("Error:", error, "\n")


# b)
f_b <- function(x) {x * exp(-x^2)}

a <- 10
n <- 50000

x <-runif(n, 0, a)

y <- f_b(x)
est <- mean(y) * a

cat("Estimare b):", est, "\n")
cat("Valoare Reala:", 1/2, "\n")


# formula for Area:
# Area = f(x1) * Δx + f(x2) * Δx + .. f(xn) * Δx
# Area = Δx (f(x1) + f(x2) + .. f(xn))
# Δx = a / n (rectangles of equal size)
# Area = a/n ((f(x1) + f(x2) + .. f(xn)))
# Area = ((f(x1) + f(x2) + .. f(xn))) / n * a
# Area = mean(f(x)) * a




