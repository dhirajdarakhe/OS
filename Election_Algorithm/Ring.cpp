// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// class Ring
// {
//     vector<int> process;
//     vector<int> token;
//     vector<int> status;
// public:
//     Ring()
//     {
//         cout<<"Enter the number of Process "
//     }
// }

// int
// main()
// {
//     Ring r;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
class Ring
{
    int token[100];
    int l = 0;

public:
    void print()
    {
        cout << "\n\t ___ Token received : ";
        for (int i = 0; i < l; i++)
            cout << token[i] << ", ";
        cout << endl;
    }

    Ring()
    {
        int winner, max = -1;

        cout << "\n\t Enter the Total Number of processes = ";
        int n;
        cin >> n;
        winner = n;
        int processes[n + 1];
        int status[n + 1];
        cout << "\n\t Enter the status of processes (1/0) .....";
        for (int i = 0; i < n; i++)
        {
            processes[i] = i;
            cout << "\n\t Enter the status of process " << i << " = ";
            cin >> status[i];
        }
        cout << "\n\t Enter the process initiator = ";
        int x;
        cin >> x;

        int i = x;
        while (i < n)
        {
            if (status[i] == 1)
            {
                int next = i + 1;
                while (next < n)
                {
                    if (status[next] == 1)
                    {
                        cout << "\n\t Election message is sent from " << i << " to " << next;
                        token[l] = i;
                        l++;
                        print();
                        winner = next;
                        break;
                    }
                    else
                    {
                        next++;
                    }
                }
            }
            i++;
        }

        cout << "\n\t Election message is sent from " << winner << " to 0";
        token[l] = winner;
        l++;
        print();
        i = 0;
        while (i < x)
        {
            if (status[i] == 1)
            {
                int next = i + 1;
                while (next < n)
                {
                    if (status[next] == 1)
                    {
                        cout << "\n\t Election message is sent from " << i << " to " << next;
                        token[l] = i;
                        l++;
                        print();
                        break;
                    }
                    else
                    {
                        next++;
                    }
                }
            }
            i++;
        }

        for (int j = 0; j < l; j++)
        {
            if (token[j] > max)
                max = token[j];
        }
        cout << "\n\t Co-ordinator is " << max;
    }
};
int main()
{   
    Ring r;
    return 0;
}