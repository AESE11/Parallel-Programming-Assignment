#include <iostream>
#include <omp.h>
int main()
{
long long total = 0;
omp_set_num_threads(4);
#pragma omp parallel
{
long long contribution =
(omp_get_thread_num() + 1) * 50;
#pragma omp critical
{
total += contribution;
std::cout
<< "Added "
<< contribution
<< " -> Total = "
<< total
<< '\n';
}
}
std::cout
<< "\nFinal Total = "
<< total
<< '\n';
return 0;
}