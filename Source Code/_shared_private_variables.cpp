#include <iostream>
#include <omp.h>
int main()
{
int sharedCounter = 100;
omp_set_num_threads(4);
#pragma omp parallel shared(sharedCounter)
{
int privateCopy = sharedCounter;
privateCopy +=
omp_get_thread_num();
std::cout
<< "Thread "
<< omp_get_thread_num()
<< " Private = "
<< privateCopy
<< " Shared = "
<< sharedCounter
<< '\n';
}
std::cout
<< "Shared Counter = "
<< sharedCounter
<< '\n';
return 0;
}