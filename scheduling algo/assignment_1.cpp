
#include <bits/stdc++.h>
using namespace std;
class Scheduling_algorithm
{
public:
    void sjf()
    {

        cout << "Enter the number of the process \n";
        int p;
        cin >> p;
        vector<pair<int, int>> process;
        cout << "Enter the Burst time \n";
        for (int i = 0; i < p; ++i)
        {
            // cout << "P" << i + 1 << " : ";
            int b;
            cin >> b;
            // cout << endl;
            cout<< "P" << i + 1 << " : " << b<< endl;
            process.push_back(
                {b, i + 1});
        }
        sort(process.begin(), process.end());
        vector<int> waiting_time;
        waiting_time.push_back(0);
        for (int i = 1; i < p; ++i)
        {
            waiting_time.push_back(waiting_time[i - 1] + process[i - 1].first);
        }
        cout << "ANS ::\n";
        printf("P BT WT TAT\n");
        float avg_wt = 0;
        for (int i = 0; i < p; ++i)
        {
            printf("P%d %d %d %d\n", process[i].second,
                   process[i].first, waiting_time[i],
                   process[i].first + waiting_time[i]);
            avg_wt += waiting_time[i];
        }
        avg_wt /= p;
        printf("\nAverage Waiting Time= %f", avg_wt);
        cout << "\n";
    }
    void fcfs()
    {
        cout << "Enter the number of the process \n";
        int p;
        cin >> p;
        vector<pair<int, int>> process;
        cout << "Enter the Burst time \n";
        for (int i = 0; i < p; ++i)
        {
            // cout << "P" << i + 1 << " : ";
            int b;
            cin >> b;
            cout<< "P" << i + 1 << " : "<< b<< endl;
            // cout << endl;
            process.push_back(
                {b, i + 1});
        }
        vector<int> waiting_time;
        waiting_time.push_back(0);
        for (int i = 1; i < p; ++i)
        {
            waiting_time.push_back(waiting_time[i - 1] + process[i - 1].first);
        }
        cout << "ANS ::\n";
        printf("P BT WT TAT\n");
        float avg_wt = 0;
        for (int i = 0; i < p; ++i)
        {
            printf("P%d %d %d %d\n", process[i].second,
                   process[i].first, waiting_time[i],
                   process[i].first + waiting_time[i]);
            avg_wt += waiting_time[i];
        }
        avg_wt /= p;
        printf("\nAverage Waiting Time= %f", avg_wt);
        cout << "\n";
    }
    void priority()
    {
        cout << "Enter the number of the process \n";
        int p;
        cin >> p;
        vector<pair<int, int>> process;
        cout << "Enter the Priority & Burst time \n";
        for (int i = 0; i < p; ++i)
        {
            int pq, b;
            cin >> pq >> b;
            cout << endl;
            process.push_back(
                {pq, b});
                cout<< "p" << i+1 <<" : "<< pq <<" : "<< b<<endl;
        }
        sort(process.rbegin(), process.rend());
        vector<int> waiting_time;
        waiting_time.push_back(0);
        for (int i = 1; i < p; ++i)
        {
            waiting_time.push_back(waiting_time[i - 1] + process[i - 1].second);
        }
        cout << "ANS ::\n";
        printf("prio BT WT TAT\n");
        float avg_wt = 0;
        for (int i = 0; i < p; ++i)
        {
            printf("%d %d %d %d\n", process[i].first,
                   process[i].second, waiting_time[i],
                   process[i].second + waiting_time[i]);
            avg_wt += waiting_time[i];
        }
        avg_wt /= p;
        printf("\nAverage Waiting Time= %f", avg_wt);
        cout << "\n";
    }
};

int main()
{
    Scheduling_algorithm os;
    cout<<"------------------------\n";
    cout<<"First come first search \n";
    os.fcfs();
    cout<<endl;
    cout<<"------------------------\n";
    cout<<"Sortest Job first \n";
    os.sjf();
    cout<<endl;
    cout<<"------------------------\n";
    cout<<"Priority alogo \n";
    os.priority();
    cout<<endl;
}
