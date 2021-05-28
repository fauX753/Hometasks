#include <iostream>

using namespace std;

int main(){
    int n,k,number,answer;
    int hi,min,mid;
    
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cin>>k;
    int arr1[k];
    for(int i=0;i<k;i++){
        cin>>arr1[i];
    }
    
    for(int i=0;i<k;i++){
        hi=n-1;
        min=0;
        mid=n/2;
        answer=-1;
        number = arr1[i];
        
        while(hi>=min){
            if(number==arr[mid]){
                answer=mid+1;
                break;
            }
            if(number<arr[mid]){
                hi=mid-1;
            }
            if(number>arr[mid]){
                min=mid+1;
            }
            mid=(min+hi)/2;
        }
        cout<<answer<<" ";
    }
}