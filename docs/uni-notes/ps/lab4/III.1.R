# III.1
outliers_mean = function(sample) {
  m = mean(sample)
  s = sd(sample)
  outliers = vector()
  j = 0
  for (i in 1:length(sample)){
    if(sample[i] < m - 2 * s | sample[i] > m + 2 * s){
      j = j + 1
      outliers[j] = sample[i]
    }
  }
  outliers
}

sample = c(1, 91, 38, 72, 13, 27, 11, 85, 5, 22, 20, 19, 8, 17, 11, 15, 13, 23, 14, 17)
outliers_mean(sample)


# III.2
outliers_iqr = function(sample){
  q1 = quantile(sample, 0.25)
  q3 = quantile(sample, 0.75)
  iqr = q3 - q1
  outliers = vector()
  j = 0
  for (i in 1:length(sample)){
    if(sample[i] < q1 - 1.5 * iqr | sample[i] > q3 + 1.5 * iqr){
      j = j + 1
      outliers[j] = sample[i]
    }
  }
  outliers
}

sample = c(1, 91, 38, 72, 13, 27, 11, 85, 5, 22, 20, 19, 8, 17, 11, 15, 13, 23, 14, 17)
outliers_iqr(sample)


# III.3
sample = scan("/Users/Roberto/documents/info/uni-notes/ps/lab4/sample2.txt")
outliers_mean(sample)
outliers_iqr(sample)
summary(sample)