
#include <bits/stdc++.h>
// #include <tread>
// #include <unistd.h>
using namespace std;
#define ll long long
mutex foo,bar;
int shared_data = 0;

void Task1()
{  
    lock (foo,bar);
    for (int i = 1; i <= 100000; ++i)
    {  
         shared_data++;
    }
    foo.unlock();
    bar.unlock();
}

int main()
{
    thread t1(Task1);
    thread t2(Task1);
    t1.join();
    t2.join();
    cout<<shared_data<<" ";
    return 0;
}

// OUTPUT
// 200000  
