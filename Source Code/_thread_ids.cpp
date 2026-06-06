#include <iostream>
#include <omp.h>
int main()
{
const int workers = 5;
omp_set_num_threads(workers);
#pragma omp parallel
{
int tid = omp_get_thread_num();
int total = omp_get_num_threads();
std::cout
<< "Thread "
<< tid
<< " out of "
<< total
<< " threads\n";
}
return 0;
}