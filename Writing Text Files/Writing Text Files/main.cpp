//
//  main.cpp
//  Writing Text Files
//
//  Created by Viral on 05/05/21.
//

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    ofstream outFile;
    string outputFileName="/Users/viralhirani/Google Drive/Udemy/Advanced C++ Programming/Writing Text Files/text.txt";
    
    //open file
    outFile.open(outputFileName);
    if(outFile.is_open()){
        outFile<<"Hello there!"<<endl;
        outFile<<123<<endl;
        outFile.close();
        cout<<"write complete"<<endl;
    }
    else{
        cout<<"couldn't open file: "<<outputFileName<<endl;
    }
    return 0;
}
