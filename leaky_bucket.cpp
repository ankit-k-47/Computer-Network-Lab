#include<bits/stdc++.h>
using namespace std;
void solve(int bucketSize, int inFlow, int outFlow, int &inBucket, int dropped, int it) {
    int totalpackets = inFlow + inBucket;
    if(totalpackets < outFlow) {
        cout<<it<<"\t\t"<<inFlow<<"\t"<<totalpackets<<"\t"<<0<<"\t\t\t"<<dropped<<"\n";
        return;
    }

    int afterFlow = totalpackets - outFlow;
    if(afterFlow > bucketSize) {
        dropped = afterFlow - bucketSize;
        inBucket = bucketSize;
    }
    else {
        dropped = 0;
        inBucket = afterFlow;
    }
    cout<<it<<"\t\t"<<inFlow<<"\t"<<outFlow<<"\t"<<inBucket<<"\t\t"<<dropped<<"\n";
}

int main() {
    int bucketSize;
    cout<<"Enter the bucket size : ";
    cin>>bucketSize;
    int outFlow;
    cout<<"Enter the outFlow rate : ";
    cin>>outFlow;
    int dropped = 0;
    int inBucket = 0;
    int n;
    cout<<"Enter the number of packets : ";
    cin>>n;
    int inFlowRate[n];
    cout<<"Enter the sequence of Packets : ";
    for(int i=0; i<n; i++) {
        int val;
        cin>>val;
        inFlowRate[i]=val;
    }
    cout<<"Iteration"<<"\t"<<"InFlow"<<"\t"<<"OutFlow"<<"\t"<<"InBucket"<<"\t"<<"Dropped"<<"\n";
    for(int i=0; i<n ; i++) {
        solve(bucketSize, inFlowRate[i], outFlow, inBucket, dropped, i+1);
    }
    return 0;
}