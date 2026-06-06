#include <iostream>
#include <omp.h>
int main()
{
omp_set_num_threads(4);
#pragma omp parallel
{
std::cout
<< "Greetings from OpenMP thread "
<< omp_get_thread_num()
<< '\n';
}
return 0;
}