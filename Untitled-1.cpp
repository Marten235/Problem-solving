#include <iostream>
using namespace std;
#include <vector>


void print(vector<int> arr)
{
  for(int i=0 ; i<arr.size(); i++)
  {
    cout << arr[i]<<",";
  }
  cout<<"\n";
}

int runningTime(vector<int> arr) 
{
  int x=0,count=0,e=0;
  for(int i=1 ; i<arr.size(); i++)
  { e=i;
    for(int j = i-1 ; j>=0;j--)
      {
       
        if(arr[j]>arr[e])
        {
          x=arr[j];
          arr[j]=arr[e];
          arr[e]=x;
          count++;
          e--;
        }
      }
  }
  return count;
}


int main()
{
  vector<int>arr;
  arr.push_back(4);
  arr.push_back(4);
  arr.push_back(3);
  arr.push_back(4);

 

  print(arr);
  cout <<runningTime(arr);
   
}