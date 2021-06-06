//
//  main.cpp
//  Vectors
//
//  Created by Viral on 05/05/21.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<double> numbers(0);
    
    cout<<"size: "<< numbers.size()<<endl;
    
    size_t capacity = numbers.capacity();
    cout<<"capacity= "<<capacity<<endl;
    
    for(int i =0; i<10000; i++){
        if(numbers.capacity() != capacity) {
            capacity = numbers.capacity();
            cout<<"New Capacity: "<<capacity<<endl;
        }
        numbers.push_back(i);
    }
    return 0;
}
