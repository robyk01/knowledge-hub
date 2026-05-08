# Graphical representations of the sample distribution

# Stem and leaf
x = c(11, 14, 21, 32, 17, 24, 21, 35, 52, 44, 21, 28, 36, 49, 41, 19, 20, 34, 37, 29)
stem(x)

# Histograms
sample = scan("/Users/Roberto/documents/info/uni-notes/ps/lab4/sample1.txt")
min = min(sample)
max = max(sample)
min
max

interval = seq(40, 100, 10)
hist(sample, breaks = interval, right = F, freq = T)

int = 6
hist(sample, breaks = int, right = F, col = "blue")

# Bar Chart
frecv = c(9, 8, 12, 3, 17, 41, 29, 35, 32, 40, 19, 8)
barplot(frecv, space = 0)

# Central Tendency
# Mean - average sum
list = c(3, 6, 4, 3, 6, 7, 8, 5)
mean(list)

# Median
# if n is odd - median is the value positioned in the middle
# if n is even - median is the mean
median(list)

# Mode - most frequent value


# Variability & Outliers
# Range is the difference between maximum and minimum

# Standard Deviation
sd(list)

# Variance
var(list)

# Quartile and interquartile
as.vector(quantile(list))
summary(list)



