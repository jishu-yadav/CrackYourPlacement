
#include <iostream>
#include<deque>
using namespace std;

int main() {
    int n;
    int a[100000];
    int k;
    cin>> n;
    for(int i=0;i<n;i++){
        cin>> a[i];
    }
    cin>>k;
    // process the 1st k elements
    deque<int>q(k);

    for(int i=0;i<k;i++){
        while(!q.empty() && a[i]>a[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    int i;
    for(i=0;i<n;i++){
        cout<<a[q.front()]<<" ";
        // 1.remove elemets which r not part of window (contraction)
        while(!q.empty() && q.front()<=i-k){
            
            q.pop_front();

        }
        
        // 2.remove elemnts which r not useful
        while(!q.empty() && a[i]>=a[q.back()]){
            q.pop_back();
        }
        // 3.add new element(expansion)
        q.push_back(i);
       
    }
    cout<<a[q.front()]<<endl;
	// your code goes here
	return 0;
}

// deque implementation.... this soln has a lit issue plz check once more....
