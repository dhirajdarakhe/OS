
// NOT_preemtive algorithm

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
    sjf(at, bt, n);
    return 0;
}

// Input

// Enter the no of Process : 4
// Enter the arrival time and brust time for process 1 :
// AT : 1
// BT : 3
// Enter the arrival time and brust time for process 2 :
// AT : 2
// BT : 4
// Enter the arrival time and brust time for process 3 :
// AT : 1
// BT : 2
// Enter the arrival time and brust time for process 4 :
// AT : 4
// BT : 4
//  AT : Arrival time
// CT : Complete time
//  BT : Brust time
//  TAT : Turn around time
// WT : Waiting time

//  >> non_ preemtive
// Output

// Process NO  AT  BT   CT   TAT  WT

//      P1      1   3    6    5   2
//      P2      2   4    10    8   4
//      P3      1   2    3    2   0
//      P4      4   4    14    10   6

// Avg TAT : 6
// Avg WT : 3

/// >>> preemtive

// Process NO  AT  BT   CT   TAT  WT   DONE  AT   BT

//      P1                                    1   3
//      P2                                    2   4
//      P3     3    0     3             1      1   2
//      P4                                    4   4

// TIME Q = 2

// Process NO  AT  BT   CT   TAT  WT

//      P1      3   0    8    5   2  -1
//      P2      7   0    12    8   4   -1
//      P3      1   0    5    2   0    -1
//      P4      10   0    14    10   6