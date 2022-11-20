#include <bits/stdc++.h>
using namespace std;
class Bully
{

    vector<int> status;
    vector<int> process;
    int coordinator;
    int n;

public:
    void election_BULLY(int ini)
    {
        cout << endl;
        int miniPri = INT_MAX;
        int pos = -1;
        cout << "Election Stater : Process NO  " << ini << " \n";
        for (int i = 0; i < n; ++i)
        {
            if (status[i] == 1 && process[i] > process[ini - 1])
            {
                cout << "Election message is sent from " << ini << " process to " << i + 1 << endl;
                if (miniPri > process[i])
                {
                    miniPri = process[i];
                    pos = i + 1;
                }
            }
        }
        for (int i = 0 ; i < n; ++i)
        {
            if (status[i] == 1 && process[i] > process[ini - 1])
            {
                cout << i + 1 << " process replied  \"OK\"  message to " << ini << endl;
            }
        }
        coordinator = miniPri;
        if (pos != -1)
        {

            election_BULLY(pos);
        }
        else
        {
            coordinator = ini;
        }
    }
    void getInput()
    {
        cout << "Enter  count of Processes :" << endl;
        cin >> n;
        status.resize(n);
        process.resize(n);

        for (int i = 0; i < n; i++)
        {
            cout << "Enter the status of processes " << i + 1 << ":(0/1)";
            cin >> status[i];
            cout << endl;
            cout << "Enter priority:";
            cin >> process[i];
        }
        cout << "Which processcess will initiate the election?: ";
        int ini;
        cin >> ini;
        election_BULLY(ini);
        cout << "Final co-ordinator is:" << coordinator << endl;
    }
};

int main()
{
    Bully b;
    b.getInput();
    return 0;
}


//INPUT

// 6
// 1 3
// 1 4
// 1 6
// 1 5
// 1 7 
// 1 2
// 2

        // Enter  count of Processes :
        // 6
        // Enter the status of processes 1:(0/1) 3

        // Enter priority: 1
        // Enter the status of processes 2:(0/1) 4 

        // Enter priority: 1
        // Enter the status of processes 3:(0/1) 6 

        // Enter priority: 1
        // Enter the status of processes 4:(0/1) 5 

        // Enter priority: 1
        // Enter the status of processes 5:(0/1) 7 

        // Enter priority: 1
        // Enter the status of processes 6:(0/1) 2

        // Enter priority:Which processcess will initiate the election?: 2


//OUTPUT
        // Election Stater : Process NO  2
        // Election message is sent from 2 process to 3
        // Election message is sent from 2 process to 4
        // Election message is sent from 2 process to 5
        // 3 process replied  "OK"  message to 2
        // 4 process replied  "OK"  message to 2
        // 5 process replied  "OK"  message to 2

        // Election Stater : Process NO  4
        // Election message is sent from 4 process to 3
        // Election message is sent from 4 process to 5
        // 3 process replied  "OK"  message to 4
        // 5 process replied  "OK"  message to 4

        // Election Stater : Process NO  3
        // Election message is sent from 3 process to 5
        // 5 process replied  "OK"  message to 3

        // Election Stater : Process NO  5
        // Final co-ordinator is:5