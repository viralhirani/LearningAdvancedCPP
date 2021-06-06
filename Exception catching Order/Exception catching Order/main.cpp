//
//  main.cpp
//  Exception catching Order
//
//  Created by Viral on 05/05/21.
//

#include <iostream>
#include <exception>
using namespace std;
void goesWrong()
{
    bool error1 = true;
    bool error2 = false;
    if (error1) {
        throw bad_alloc();
    }
    if(error2){
        throw exception();
    }
}
int main(int argc, const char * argv[]) {
    try {
        goesWrong();
    }
    catch(bad_alloc& e) {
        cout<<"Catching Bad Alloc: "<< e.what()<<endl;
    }
    catch(exception& e) {
        cout<<"Catching exception: "<< e.what()<<endl;
    }
    return 0;
}
