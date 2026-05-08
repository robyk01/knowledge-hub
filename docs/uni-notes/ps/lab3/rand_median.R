RandMedian = function(S) {
  n = length(S)
  n_samples = ceiling(n^(3/4))
  
  R = sample(S, size=n_samples, replace=T)
  
  R = sort(R)
  
  d_idx = max(1, floor(n_samples/2 - sqrt(n)))
  d = R[d_idx]
  
  u_idx = max(1, floor(n_samples/2 + sqrt(n)))
  u = R[u_idx]
  
  C = S[S >= d & S <= u]
  ld = sum(S < d)
  lu = sum(S > u)
  
  if (ld > n/2 | lu > n/2 | length(C) > 4*n_samples) {
    return("no median found")
  }
  C = sort(C)
  return(C[floor(n/2) - ld + 1])
}

RandMedian(c(1, 2, 3, 4, 5))

