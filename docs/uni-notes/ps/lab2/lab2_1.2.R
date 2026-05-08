area_MC = function(N, a, b, c, d){
  N_C = 0
  for(i in 1:N){
    x = runif(1,a,b)
    y = runif(1,c,d)
    if(y < f(x))
      N_C = N_C+1
  }
  return(N_C/N * (b - a) * (d - c))
}
f = function(x){
  return(-2x^2+5x-2)
}
exact_area = integrate(f,1/2,2)
rel_error = abs(area_MC-exact_area)/exact_area
