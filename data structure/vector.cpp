

#include <vector>
#include <iostream>
using namespace::std;

void testfunc(vector<int> &a1){   // if no &, it will make a copy of vector
    a1.push_back(999);
    a1.push_back(998);

    cout <<"last " << a1[a1.size()-1] <<endl;
    // int b;
    cout <<"length " << a1.size() <<endl;
    a1.pop_back(); 
    cout << "poped length " << a1.size() << endl;
    return;
}

int main(){
    vector<int> a1;
    a1.push_back(1);
    a1.push_back(2);
    a1.push_back(32);
    cout << "a1[0]  " << a1[0] << " " << endl;
    cout << "a1 size " << a1.size() << " " << endl;
    testfunc(a1);
    cout << "last  " << a1[a1.size()-1] << " " << endl;
}