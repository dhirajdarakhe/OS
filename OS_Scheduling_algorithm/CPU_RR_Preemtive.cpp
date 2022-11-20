
// Preemtive algorithm

#include <bits/stdc++.h>
using namespace std;
#define ll long long
void rr(int at[], int bt[], int n)
{
    int ct[n], tat[n], wt[n], bt1[n], at1[n];

    vector<pair<int, int>> proc(n);

    int time_quantum = -1;
    cout << "Enter the time Quantum : ";
    cin >> time_quantum;

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
            if (done[i] == true && at1[i] <= minAT)
            {
                minAT = at1[i];
                pos = i;
            }
        }

        if (pos != -1)
        {

            if (bt1[pos] >= time_quantum)
            {
                bt1[pos] -= time_quantum;
                running_time += time_quantum;
            }
            else
            {
                running_time += bt1[pos];
                bt1[pos] = 0;
            }
            at1[pos] = running_time;

            if (bt1[pos] == 0)
            {
                done[pos] = false;
                ct[pos] = running_time;
            }
        }
        else
        {
            running_time++;
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
    ll sumtat = 0;
    ll sumwt = 0;
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
    rr(at, bt, n);
    return 0;
}

// Input  1 )

// Enter the no of Process : 4
// Enter the arrival time and brust time for process 1 :      
// AT : 0 8
// BT : Enter the arrival time and brust time for process 2 : 
// AT : 1 5
// BT : Enter the arrival time and brust time for process 3 : 
// AT : 2 10
// BT : Enter the arrival time and brust time for process 4 : 
// AT : 3 11
// BT : Enter the time Quantum : 6


// Output
// Process NO  AT  BT   CT   TAT  WT 

//      P1      0   8    25    25   17
//      P2      1   5    11    10   5
//      P3      2   10    29    27   17
//      P4      3   11    34    31   20



// Input 2)

// Enter the no of Process : 3
// Enter the arrival time and brust time for process 1 :      
// AT : 1 10
// BT : Enter the arrival time and brust time for process 2 : 
// AT : 2 5
// BT : Enter the arrival time and brust time for process 3 : 
// AT : 3 8
// BT : Enter the time Quantum : 2

// Process NO  AT  BT   CT   TAT  WT   

//      P1      1   10    24    23   13
//      P2      2   5    16    14   9  
//      P3      3   8    22    19   11 
// Avg TAT : 18
// Avg WT : 11