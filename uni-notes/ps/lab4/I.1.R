# I.1 
# Draw a stem and leaf plot for the sample from "sample1.txt"
sample = scan("/Users/Roberto/documents/info/uni-notes/ps/lab4/sample1.txt")
stem(sample)


# I.2
# The file ”unemploy2012.csv” contains the unemployment rates from 2012 in a majority of european countries (with two columns named ’country’ and ’rate’). Draw the correspond- ing histogram using as intervals (0, 4], (4, 6], (6, 8], (8, 10], (10, 12], (12, 14] and (14, 30].
tablou = read.csv("/Users/Roberto/documents/info/uni-notes/ps/lab4/unemploy2012.csv", header = T, sep = ';')
rate = tablou[['rate']]

hist(rate, breaks = c(0, 4, 6, 8, 10, 12, 14, 30), right = T)


# I.3
# The file ”life expect.csv” contains the life expectancy (at birth, in 2012) in some european countries (with three columns named ’country’, ’female’ and ’male’). Draw the histograms for males and females using seven intervals (of equal length) in each case.

tablou = read.csv("/Users/Roberto/documents/info/uni-notes/ps/lab4/life_expect.csv", header = T, sep = ',')
male = tablou[['male']]
female = tablou[['female']]

hist(male, breaks = seq(min(male), max(male), length.out = 8))
hist(female, breaks = seq(min(female), max(female), length.out = 8))
  
  
  
  
  
  