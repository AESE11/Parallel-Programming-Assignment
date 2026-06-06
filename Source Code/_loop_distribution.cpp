#include <iostream>
#include <omp.h>
int main()
{
const int N = 20;
int values[N];
#pragma omp parallel for schedule(static)
for(int i = 0 ; i < N ; i++)
{
values[i] = i * 5;
std::cout
<< "Thread "
<< omp_get_thread_num()
<< " processed index "
<< i
<< '\n';
}
return 0;
}