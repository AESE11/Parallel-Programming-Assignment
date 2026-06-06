#include <iostream>
#include <omp.h>
int main()
{
int lastResult = 0;
#pragma omp parallel for lastprivate(lastResult)
for(int i = 0 ; i < 20 ; i++)
{
lastResult = i * 3;
}
std::cout
<< "Last Iteration Value = "
<< lastResult
<< '\n';
return 0;
}