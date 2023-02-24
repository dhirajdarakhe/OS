
#include <bits/stdc++.h>
// #include <tread>
// #include <unistd.h>
using namespace std;
#define ll long long
int shared_data = 0;
void Task1()
{
    for (int i = 1; i <= 100000; ++i)
    {  
         shared_data++;
    }
}

int main()
{
    thread t1(Task1);
    thread t2(Task1);
    t1.join();
    t2.join();
    cout<<shared_data<<" :  it should be 200000 ";
    return 0;
}

// OUTPUT
// 143130 

// if two thread are accessing the same data then it leads to the inconsistancy
// and output will be dependent on the thread scheduling alogorithm
