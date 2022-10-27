#include <iostream>

using namespace std;

void func2(int x){
    int m,n;
    m = x + 1;
    n = x + 2;
}

void func1(int a,int b){
    int x = a + b;
    func2(x);//breakpoint to see the function stack
    x = x + 10086;
}

int main(){
    int a = 1,b = 2,c = 3;
    func1(a,b);
    c = a + b;
    cout<<c<<endl;
    return 0;
}