#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> leftheap;                             //maxheap;
    priority_queue<int, vector<int>, greater<int>> rightheap; //minheap

    int d;
    cin >> d;
    leftheap.push(d);
    float med = d;
    cout << "Median " << med << endl;

    //input all elements
    while (d != -1)
    {
        cin >> d;
        //logic
        if (leftheap.size() > rightheap.size())
        {
            if (d < med)
            {
                rightheap.push(leftheap.top());
                leftheap.pop();
                leftheap.push(d);
            }
            else
            {
                rightheap.push(d);
            }
            med = (leftheap.top() + rightheap.top()) / 2.0;
        }
        else if (leftheap.size() == rightheap.size())
        {
            if (d < med)
            {
                leftheap.push(d);
                med = leftheap.top();
            }
            else
            {
                rightheap.push(d);
                med = rightheap.top();
            }
        }
        else
        {
            //3rd case when rightheap > leftheap
            if (d > med)
            {
                leftheap.push(rightheap.top());
                rightheap.pop();
                rightheap.push(d);
            }
            else
            {
                leftheap.push(d);
            }
            med = (leftheap.top() + rightheap.top()) / 2.0;
        }
        cout << "Med " << med << endl;
    }
    return 0;
}
// median of running integers
