#include <bits/stdc++.h>
using namespace std;
#define ll long long
void fcfs(int at[], int bt[], int n)
{
    int t = 0;
    int ct[n], tat[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        ct[i] = bt[i] + max(at[i], t);
        t = ct[i];
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
    for (int i = 0; i < n; ++i)
    {
        cout << "     P" << i + 1 << "      " << at[i] << "   " << bt[i] << "    " << ct[i] << "    " << tat[i] << "   " << wt[i] << endl;
    }
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
    fcfs(at, bt, n);
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







// Output



// Process NO  AT  BT   CT   TAT  WT
//      P1      0   2    2    2   0
//      P2      1   2    4    3   1
//      P3      5   3    8    3   0
//      P4      6   4    12    6   2
