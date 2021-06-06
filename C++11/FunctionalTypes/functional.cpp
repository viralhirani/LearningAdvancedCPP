#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>

using namespace std;
// create function to test the string size
bool check(string& test)
{
    return test.size() == 3;
}
class Test
{
public:
    bool operator()(string& test)
    {
        return test.size() == 5;
    }
};
// we cant to accept anything which is callable and returns bool and accepts string.
//we can use functional type to achive this.
void run(function<bool(string&)> check) // check is functional type which returns bool and accepts string ref.
{
    string test = "stars";
    cout << check(test)<<endl;
}
using namespace std;
// The standard function type, which let's us define a type/reference to any callable reference 
int main()
{
    int size = 5;
    vector<string> vec{"one", "two", "three"};

    // use lambda with count_if
    auto lambda = [size](string test){return test.size() == size;};
    int count = count_if(vec.begin(), vec.end(), lambda);
    cout <<count<<endl;
    // use function pointer with count_if
    count = count_if(vec.begin(), vec.end(), check);
    cout <<count<<endl;

    // Use functor with count_if
    Test testObj;
    count = count_if(vec.begin(), vec.end(), testObj);
    cout <<count<<endl;

    // In all above cases we are passing different callable types to count_if.
    // there we are passing callable types which accepts string and returns bool.
    // How does it internally do that, it uses standard function.
    // we can create a function which accpets anything which is callable and returns bool and accepts string
    // pass all callable things to that function and check.
    run(lambda);
    run(check);
    run(testObj);


    return 0;
}