//
//  main.cpp
//  StandardExceptions
//
//  Created by Viral on 24/04/21.
//

#include <iostream>
using namespace std;

class CanGoWrong {
public:
    CanGoWrong() {
        char *pMemory = new char[9999999999999999];
        delete [] pMemory;
    }
};

int main(int argc, const char * argv[]) {
    try {
        CanGoWrong wrong;
    }
    catch(bad_alloc &e) {
        cout<<"Cought the exception. "<<e.what()<<endl;
    }
    return 0;
}
