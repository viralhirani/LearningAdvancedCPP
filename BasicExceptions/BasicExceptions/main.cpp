//
//  main.cpp
//  BasicExceptions
//
//  Created by Viral on 24/04/21.
//

#include <iostream>
using namespace std;

void mightGoWrong()
{
    bool error = true;
    
    if(error) {
        throw 8;
    }
}

void mightGoWrongStr()
{
    bool error1 = false;
    bool error2 = true;
    
    if(error1) {
        throw "Somthing went wrong";
    }
    if (error2) {
        throw string("Somthing else went wrong");
    }
}

int main(int argc, const char * argv[]) {

    try {
        mightGoWrong();
    }
    catch(int e) {
        cout<<"Error code: "<< e << endl;
    }
    try{
        mightGoWrongStr();
    }
    catch(char const* e) {
        cout<< "Error message: "<<e<<endl;
    }
    catch(string& e) {
        cout<< "String error message: "<<e<<endl;
    }
    cout<<"Still running.."<<endl;
    return 0;
}
