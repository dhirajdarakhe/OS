
// Preemtive algorithm

#include <bits/stdc++.h>
using namespace std;
#define ll long long
void sjf(int at[], int bt[], int n)
{
    int ct[n], tat[n], wt[n], bt1[n], at1[n];

    vector<pair<int, int>> proc(n);

    vector<bool> done(n);
    for (int i = 0; i < n; ++i)
    {
        done[i] = true;
        bt1[i] = bt[i];
        at1[i] = at[i];
        proc[i] = {at[i], bt[i]};
    }

    int running_time = 0;
    while (1)
    {
        ll end = 0;
        for (int i = 0; i < n; ++i)
            if (!done[i])
                end++;
        if (end == n)
            break;

        int minBT = INT_MAX;
        int minAT = running_time;
        int pos = -1;
        for (int i = 0; i < n; ++i)
        {
            if (done[i] == true && at1[i] <= minAT && minBT > bt1[i])
            {
                minBT = bt1[i];
                pos = i;
            }
        }

        running_time++;
        
        if (pos != -1)
        {
            at1[pos] = running_time;
            bt1[pos]--;

            if (bt1[pos] == 0)
            {
                done[pos] = false;
                ct[pos] = running_time;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    cout << " AT : Arrival time\nCT : Complete time\n BT : Brust time \n TAT : Turn around time \nWT : Waiting time\n";
    cout << "Process NO "
         << " AT "
         << " BT "
         << "  CT "
         << "  TAT "
         << " WT " << endl;
    cout << endl;
    float sumtat = 0;
    float sumwt = 0;
    for (int i = 0; i < n; ++i)
    {
        sumtat += tat[i];
        sumwt += wt[i];
        cout << "     P" << i + 1 << "      " << at[i] << "   " << bt[i] << "    " << ct[i] << "    " << tat[i] << "   " << wt[i] << endl;
    }
    cout << "Avg TAT : " << sumtat / n << endl;
    cout << "Avg WT : " << sumwt / n << endl;
}
int main()
{
    int n;
    cout << "Enter the no of Process : ";
    cin >> n;
    int at[n];
    int bt[n];
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter the arrival time and brust time for process " << i + 1 << " : \n";
        cout << "AT : ";
        cin >> at[i];
        cout << "BT : ";
        cin >> bt[i];
    }
    sjf(at, bt, n);
    return 0;
}

// Input 1)
// Enter the no of Process : 5
// Enter the arrival time and brust time for process 1 :      
// AT : 2 6
// BT : Enter the arrival time and brust time for process 2 : 
// AT : 5 2
// BT : Enter the arrival time and brust time for process 3 : 
// AT : 1 8
// BT : Enter the arrival time and brust time for process 4 : 
// AT : 0 3
// BT : Enter the arrival time and brust time for process 5 : 
// AT : 4 4
// BT :  AT : Arrival time


// Output
// Process NO  AT  BT   CT   TAT  WT  

//      P1      2   6    15    13   7 
//      P2      5   2    7    2   0   
//      P3      1   8    23    22   14
//      P4      0   3    3    3   0   
//      P5      4   4    10    6   2  
// Avg TAT : 9.2
// Avg WT : 4.6



// Input 2)

// Enter the no of Process : 5
// Enter the arrival time and brust time for process 1 :      
// AT : 3 1
// BT : Enter the arrival time and brust time for process 2 : 
// AT : 1 4
// BT : Enter the arrival time and brust time for process 3 : 
// AT : 4 2
// BT : Enter the arrival time and brust time for process 4 : 
// AT : 0 6
// BT : Enter the arrival time and brust time for process 5 : 
// AT : 2 3
// BT :  AT : Arrival time

// Process NO  AT  BT   CT   TAT  WT 

//      P1      3   1    4    1   0  
//      P2      1   4    6    5   1  
//      P3      4   2    8    4   2   
//      P4      0   6    16    16   10
//      P5      2   3    11    9   6  
// Avg TAT : 7
// Avg WT : 3.8