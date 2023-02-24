#include <bits/stdc++.h>
// #include <tread>
// #include <unistd.h>
using namespace std;
#define ll long long
void Task1()
{
    for (int i = 0; i < 10; ++i)
    {
        sleep(1);
        cout << "task 1 : " << i << endl;
        fflush(stdout);
    }
}
void Task2()
{
    for (int i = 0; i < 10; ++i)
    {
        sleep(1);
        cout << "task 2 : " << i << endl;
        fflush(stdout);
    }
}
int main()
{
    thread t1(Task1);
    thread t2(Task2);
    t1.join();
    t2.join();
    return 0;
}

// OUTPUT
// task 2 : 0task 1 :
// 0
// task 2 : 1
// task 1 : 1
// task 2 : 2
// task 1 : 2
// task 1 : 3
// task 2 : 3
// task 1 : 4
// task 2 : 4
// task 1 : task 2 : 55

// task 2 : 6
// task 1 : 6
// task 2 : task 1 : 77

// task 2 : task 1 : 88

// task 1 : task 2 : 99


// C++ Sleep()
// Sleep function in C++ is used to suspend the execution of a 
// thread or a process for a specified period of time temporarily. 

// C++ fflush()
// The fflush() function in C++ flushes any buffered data to the respective device.

// Buffered data is the temporary or application specific data stored in the physical memory of the computer until a certain time.

// The fflush() function is defined in <cstdio> header file.











