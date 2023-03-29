// given a colection of integers a1, a2, ..., an. Perform a sequence of operations of types below on a collection of integers:
// insert x: insert an element x to the collection
// delete-max; remove and return the maximum element of the collection
// input: integer n, an array a[], a size n, next subsequence lines contains an operation of above formaton each line, the input terminated by *
// output: write the result for each operation of type delete-max
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
        
    std::string op;
    while (std::cin >> op && op != "*")
    {
        int x;
        if (op == "insert")
        {
            std::cin >> x;
            a.push_back(x);
            std::push_heap(a.begin(), a.end());
        }
        else if (op == "delete-max")
        {
            std::cout << a[0] << '\n';
            std::pop_heap(a.begin(), a.end());
            a.pop_back();
        }
    }
}

