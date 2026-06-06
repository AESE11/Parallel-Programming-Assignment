#include <iostream>
#include <omp.h>
int main()
{
const int THREADS = 4;
const int PAD = 8;
const long N = 100000;
long double cacheLine[THREADS][PAD] = {0};
long double step = 1.0L / N;
omp_set_num_threads(THREADS);
#pragma omp parallel
{
int id = omp_get_thread_num();
int total = omp_get_num_threads();
for(long i=id ; i<N ; i+=total)
{
long double x =
(i + 0.5L) * step;
cacheLine[id][0] +=
4.0L/(1.0L+x*x);
}
}
long double pi = 0;
for(int i=0;i<THREADS;i++)
pi += cacheLine[i][0];
std::cout
<< "PI = "
<< pi * step
<< '\n';
return 0;
}