#include <iostream>
#include <omp.h>
int main()
{
int values[6];
omp_set_num_threads(6);
#pragma omp parallel
{
int id = omp_get_thread_num();
values[id] = id * id;
std::cout
<< "Thread "
<< id
<< " reached barrier\n";
#pragma omp barrier
std::cout
<< "Thread "
<< id
<< " passed barrier\n";
}
std::cout << "\nResults:\n";
for(int i = 0 ; i < 6 ; i++)
std::cout << values[i] << ' ';
return 0;
}