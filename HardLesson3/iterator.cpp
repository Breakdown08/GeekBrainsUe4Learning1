#include <iostream>

class num_iterator
{
private:
    int i;
public:
    explicit num_iterator(int position = 0): i(position) {}

    int operator*() const { return i; }

    num_iterator& operator++()
    {
        ++i;
        return *this;
    }

    bool operator!=(const num_iterator& toCompare)
    {
        return i != toCompare.i;
    }
};

class num_range
{
private:
    int a;
    int b;
public:
    num_range(int from, int to): a(from), b(to) {}

    num_iterator begin() const { return num_iterator(a); }

    num_iterator end() const { return num_iterator(b); }
};

int main()
{
    num_range range(0, 10);

    for (auto i : range)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
