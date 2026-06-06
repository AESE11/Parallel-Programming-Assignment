#include <iostream>
int main()
{
const long N = 100000;
long double width = 1.0L / N;
long double area  = 0.0L;
for(long i = 0 ; i < N ; i++)
{
long double point =
(i + 0.5L) * width;
area +=
4.0L / (1.0L + point * point);
}
std::cout
<< "PI = "
<< area * width
<< '\n';
return 0;
}