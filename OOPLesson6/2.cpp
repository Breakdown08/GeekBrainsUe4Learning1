#include <iostream>
using namespace std;
ostream& endll(ostream& os) 
{
    os.flush();
    return os << endl << endl;
}
int main()
{
    cout << "first string" << endll;
    cout << "second string" << endl;

    return 0;
}