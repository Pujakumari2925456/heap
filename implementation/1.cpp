#include<iostream>
using namespace std;
//class started

class MaxHeap{
  public:
  int *arr;
  int size;
  int total_size;
  //constructor
  MaxHeap(int n){
    arr=new int [n];
    size=0;
    total_size=n;
  }
  //insertion(step up)
  void insert(int value){
    if(size==total_size){
      cout<<"overflow"<<endl;
    }
    else{
      arr[size]=value;
      int index=size;
      size++;
while( index>0 && arr[index]>arr[(index-1)/2]){
    swap(arr[index],arr[(index-1)/2]);
    index=(index-1)/2;
  }
  cout<<arr[index]<<" "<<"inserted into the heap"<<endl;

  

}
    }
    //heapify(step down) sab daal lo phir 
    void heapify(int index){
      int largest=index;
      int left=2*index+1;
      int right=2*index+2;
      if(left<size && arr[left]>arr[largest]){
        largest=left;
      }
      if(right<size && arr[right]>arr[largest]){
        largest=right;
      }
      if(largest!=index){
        swap(arr[largest],arr[index]);
        heapify(largest);
      }
      return;
    }
    //delete
    void deleteM(){
      if(size==0){
        cout<<"heap underflow"<<endl;
        return;
      }
      cout<<arr[0];
      arr[0]=arr[size-1];
      size--;
      if (size==0){
        return;
      }
      heapify(0);

    }
    //printing
void print(int size){
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" "<<endl;
  }
  }
  //correct position m daalao
  //compare with its paremts
  
  
};
int main(){
  MaxHeap H1(10);
  H1.insert(30);
  H1.insert(20);
   H1.insert(50);
  H1.insert(200);
  H1.print(10);
  H1.deleteM();
  H1.print(9);
}