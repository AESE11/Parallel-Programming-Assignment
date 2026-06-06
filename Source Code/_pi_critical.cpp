#include <iostream>
#include <omp.h>
int main()
{
const long N = 100000;
long double piValue = 0.0L;
long double step = 1.0L / N;
omp_set_num_threads(4);
#pragma omp parallel
{
int id = omp_get_thread_num();
int total = omp_get_num_threads();
long double privateSum = 0.0L;
for(long i=id ; i<N ; i+=total)
{
long double x =
(i+0.5L)*step;
privateSum +=
4.0L/(1.0L+x*x);
}
#pragma omp critical
{
piValue +=
privateSum * step;
}
}
std::cout
<< "PI = "
<< piValue
<< '\n';
return 0;
}