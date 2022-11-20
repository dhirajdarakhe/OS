#include <bits/stdc++.h>
using namespace std;
#define ll long long
void fcfs(int at[], int bt[], int pt[], int n)
{

    // process
    int t = 0;
    int ct[n], tat[n], wt[n], pt1[n];
    for (int i = 0; i < n; i++)
        pt1[i] = pt[i];
    while (1)
    {
        int pri = INT_MAX;
        int pos = -1;
        int end = 0;
        for (int j = 0; j < n; ++j)
        {
            if (pt1[j] != -1)
            {
                if (pri > pt1[j] && at[j] <= t)
                {
                    pri = pt1[j];
                    pos = j;
                }
            }
            else
            {
                end++;
            }
        }
        cout << pos << " " << endl;
        if (end == n)
            break;
        if (pos == -1)
        {
            t++;
            continue;
        }
        ct[pos] = bt[pos] + max(at[pos], t);
        t = ct[pos];
        pt1[pos] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // print
    cout << " AT : Arrival time\nCT : Complete time\n BT : Brust time \n TAT : Turn around time \nWT : Waiting time\n";
    cout << "Process NO "
         << " PT "
         << " AT "
         << " BT "
         << "  CT "
         << "  TAT "
         << " WT " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "     P" << i + 1 << "      " << pt[i] << "  " << at[i] << "   " << bt[i] << "    " << ct[i] << "    " << tat[i] << "   " << wt[i] << endl;
    }
}
int main()
{
    int n;
    cout << "Enter the no of Process : ";
    cin >> n;
    int at[n];
    int bt[n];
    int pt[n];
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter the Priority , arrival time and brust time for process " << i + 1 << " : \n";
        cout << "P : ";
        cin >> pt[i];
        cout << "AT : ";
        cin >> at[i];
        cout << "BT : ";
        cin >> bt[i];
    }
    fcfs(at, bt, pt, n);
    return 0;
}

// Input

// Enter the no of Process :
// 4
// Enter the arrival time and brust time for process 1 :
// AT : 0
// BT : 2
// Enter the arrival time and brust time for process 2 :
// AT : 1
// BT : 2
// Enter the arrival time and brust time for process 3 :
// AT : 5
// BT : 3
// Enter the arrival time and brust time for process 4 :
// AT : 6
// BT : 4
//  AT : Arrival time
// CT : Complete time
//  BT : Brust time
//  TAT : Turn around time
// WT : Waiting time

// OUT put

// Process NO  PT  AT  BT   CT   TAT  WT
//      P1      2  0   3    3    3   0
//      P2      6  2   5    18    16   11
//      P3      3  1   4    7    6   2
//      P4      5  4   2    13    9   7
//      P5      7  6   9    27    21   12
//      P6      4  5   4    11    6   2
//      P7      10  7   10    37    30   20