#include <iostream>
#include <omp.h>
int main()
{
int counter = 0;
omp_lock_t myLock;
omp_init_lock(&myLock);
#pragma omp parallel for
for(int i=0;i<1000;i++)
{
omp_set_lock(&myLock);
counter++;
omp_unset_lock(&myLock);
}
omp_destroy_lock(&myLock);
std::cout
<< "Counter = "
<< counter
<< '\n';
return 0;
}