
// NOT_preemtive algorithm

#include <bits/stdc++.h>
using namespace std;
#define ll long long
void sjf(int at[], int bt[], int n)
{
    vector<pair<int, int>> process;
    int ct[n], tat[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        process.push_back({at[i], bt[i]});
    }

    int running_time = 0;
    for (int i = 0; i < n; ++i)
    {

        int maxAT = INT_MAX;
        int maxBT = INT_MAX;
        int processNO = -1;
        bool found_process = false;

        // find the process to execute
        for (int j = 0; j < n; ++j)
        {
            if (process[j].first == -1) // if process is already executed
                continue;
            else if (at[j] <= running_time) // take the processes which were waiting
            {
                if (maxAT >= at[j] && maxBT > bt[j])
                {
                    maxAT = at[j];
                    maxBT = bt[j];
                    processNO = j;
                    found_process = true;
                }
            }
        }

        // if process not found
        if (found_process == false)
        {

            for (int j = 0; j < n; ++j)
            {
                if (process[j].first == -1) // if process is already executed
                    continue;
                else
                {
                    if (maxAT >= at[j] && maxBT > bt[j])
                    {
                        maxAT = at[j];
                        maxBT = bt[j];
                        processNO = j;
                    }
                }
            }
        }

        ct[processNO] = bt[processNO] + max(running_time, at[processNO]);
        running_time = ct[processNO];
        process[processNO].first = -1;
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

// Output

// Process NO  AT  BT   CT   TAT  WT

//      P1      1   3    6    5   2
//      P2      2   4    10    8   4
//      P3      1   2    3    2   0
//      P4      4   4    14    10   6

// Avg TAT : 6
// Avg WT : 3
