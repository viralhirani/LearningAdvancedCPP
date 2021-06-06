#include<iostream>
#include <vector>
using namespace std;

bool match(string test)
{
    return test.size() == 3;
}

int countMatchingString(vector<string>& texts, bool (*match)(string test))
{
    int count = 0;
    for (auto& text : texts) {
        if (match(text)) {
            count++;
        }
    }
        return count;
}

int main()
{
    vector<string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("four");
    texts.push_back("two");

    cout<<countMatchingString(texts,match)<<endl;
    return 0;
}