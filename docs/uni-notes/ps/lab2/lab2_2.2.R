MC_improved_integration = function(N) {
  sum = 0;
  for(i in 1:N) {
    u = rexp(1, rate = 3);
    
    sum = sum + exp(-2uu)/(3exp(-3u));
  }
  return(sum/N)
}

est = MC_improved_integration(50000)
abs_error = abs(est - sqrt(pi/8))
rel_error = abs_error / sqrt(pi/8)
  MC_imprvd_integr_average= function(k, N) {
    estimates = 0;
    for(i in 1:k)
      estimates[i] = MC improved integration(N);
    print(mean(estimates));
    print(sd(estimates));
  }