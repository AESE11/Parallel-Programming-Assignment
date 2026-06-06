#include <iostream>
#include <omp.h>
int main()
{
const int THREADS = 4;
const long N = 100000;
long double partial[THREADS] = {0};
long double step = 1.0L / N;
omp_set_num_threads(THREADS);
#pragma omp parallel
{
int me = omp_get_thread_num();
int workers = omp_get_num_threads();
for(long i = me ; i < N ; i += workers)
{
long double x =
(i + 0.5L) * step;
partial[me] +=
4.0L / (1.0L + x * x);
}
}
long double result = 0;
for(int i = 0 ; i < THREADS ; i++)
result += partial[i];
std::cout
<< "PI = "
<< result * step
<< '\n';
return 0;
}