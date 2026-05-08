# II.1
# Compute the mean and the median for the sample from ”sample1.txt”.
sample = scan("/Users/Roberto/documents/info/uni-notes/ps/lab4/sample1.txt")

mean(sample)
median(sample)


# II.2
# Compute the mean and the median for the samples from ”life expect.csv”.
csv = read.csv("/Users/Roberto/documents/info/uni-notes/ps/lab4/life_expect.csv", header = T, sep = ',')
sample_male = csv[['male']]
sample_female = csv[['female']]

mean(sample_male)
mean(sample_female)

median(sample_male)
median(sample_female)


# II.3
# Write a function to compute the mode for a given sample.
csv = read.csv("/Users/Roberto/documents/info/uni-notes/ps/lab4/life_expect.csv", header = T, sep = ',')
sample_male = csv[['male']]

mode = function(sample){
  counts = table(sample)
  mode_val = counts[counts == max(counts)]
  return(mode_val[1])
}

result = mode(sample_male)
result


