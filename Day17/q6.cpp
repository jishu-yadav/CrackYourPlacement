#include <iostream>
using namespace std;
class Fun{
    public:
    void operator()(string s){
        cout<<"having fun with "<<s;
    }
};
int main() {
    Fun f;
    f("c++");

}
//functors: functional objects
