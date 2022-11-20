#include <bits/stdc++.h>
using namespace std;

class MemManage
{
public:
    void firstFit(int a[], int b1[], int n, int m)
    {
        int blocks[n];
        int b[m];
        for (int i = 0; i < m; i++)
        {
            b[i] = b1[i];
        }
        for (int i = 0; i < n; i++)
        {
            int is_alloc = -1;
            for (int j = 0; j < m; j++)
            {
                if (a[i] <= b[j])
                {
                    b[j] -= a[i];
                    is_alloc = (j + 1);
                    break;
                }
            }
            blocks[i] = is_alloc;
        }
        cout << "\nProcess No.\t\tProcess size\t\tBlock allocated\n";
        for (int i = 0; i < n; i++)
        {
            cout << "   " << (i + 1) << "\t\t\t"
                 << "\t" << a[i] << "\t\t\t" << blocks[i] << endl;
        }
    }



    void nextFit(int a[], int b1[], int n, int m)
    {
        int blocks[n];
        int b[m];
        for (int i = 0; i < m; i++)
        {
            b[i] = b1[i];
        }
        int curpos = 0;
        for (int i = 0; i < n; i++)
        {
            int is_alloc = -1;
            int pos = curpos;

            do
            {
                if (a[i] <= b[pos])
                {
                    b[pos] -= a[i];
                    curpos = pos;
                    is_alloc = 1;
                    break;
                }
                pos++;
                pos %= m;
            } while (pos != curpos);

            if (is_alloc == -1)
            {
                blocks[i] = is_alloc;
            }
            else
            {
                blocks[i] = curpos + 1;
            }
        }
        cout << "\nProcess No.\t\tProcess size\t\tBlock allocated\n";
        for (int i = 0; i < n; i++)
        {
            cout << "   " << (i + 1) << "\t\t\t"
                 << "\t" << a[i] << "\t\t\t" << blocks[i] << endl;
        }
    }

    void bestFit(int a[], int b1[], int n, int m)
    {

        int block[n];
        int b[m];
        for (int i = 0; i < m; i++)
        {
            b[i] = b1[i];
        }
        for (int i = 0; i < n; i++)
        {
            int minblock = -1;
            int minpos = -1;
            for (int j = 0; j < m; j++)
            {
                if (b[j] >= a[i])
                {
                    if (minpos != -1)
                    {
                        if (minblock > b[j])
                        {
                            minblock = b[j];
                            minpos = j + 1;
                        }
                    }
                    else
                    {
                        minblock = b[j];
                        minpos = j + 1;
                    }
                }
            }
            block[i] = minpos;
            if (minpos != -1)
            {
                b[minpos - 1] -= a[i];
            }
        }
        cout << "\nProcess No.\t\tProcess size\t\tBlock allocated\n";
        for (int i = 0; i < n; i++)
        {
            cout << "   " << (i + 1) << "\t\t\t"
                 << "\t" << a[i] << "\t\t\t" << block[i] << endl;
        }
    }

    void worstFit(int a[], int b1[], int n, int m)
    {

        int block[m];
        int b[n];
        for (int i = 0; i < m; i++)
        {
            b[i] = b1[i];
        }
        for (int i = 0; i < n; i++)
        {
            int maxblock = -1;
            int maxpos = -1;
            for (int j = 0; j < m; j++)
            {
                if (b[j] >= a[i])
                {
                    if (maxpos != -1)
                    {
                        if (maxblock < b[j])
                        {
                            maxblock = b[j];
                            maxpos = j + 1;
                        }
                    }
                    else
                    {
                        maxblock = b[j];
                        maxpos = j + 1;
                    }
                }
            }
            block[i] = maxpos;
            if (maxpos != -1)
            {
                b[maxpos - 1] -= a[i];
            }
        }
        cout << "\nProcess No.\t\tProcess size\t\tBlock allocated\n";
        for (int i = 0; i < n; i++)
        {
            cout << "   " << (i + 1) << "\t\t\t"
                 << "\t" << a[i] << "\t\t\t" << block[i] << endl;
        }
    }
};

int main()
{

    int p, b;

    cout << "Enter number of processes: ";
    cin >> p;
    cout << "\nEnter number of memory blocks: ";
    cin >> b;

    int ps[p], bs[b];

    cout << "\nEnter data for processes:" << endl;
    for (int i = 0; i < p; i++)
    {
        cout << "\nEnter size of process " << (i + 1) << " : ";
        cin >> ps[i];
    }

    cout << "\nEnter data for memory blocks:" << endl;
    for (int i = 0; i < b; i++)
    {
        cout << "\nEnter size of block " << (i + 1) << " : ";
        cin >> bs[i];
    }

    int ch = -1;
    MemManage m1;

    do
    {

        cout << "\n--------  Menu  ---------\n 1. First fit\n 2. Next fit\n 3. Best fit\n 4. Worst fit\n 5. Exit\nEnter Choice: ";
        cin >> ch;

        switch (ch)
        {

        case 1:

            m1.firstFit(ps, bs, p, b);
            break;
        case 2:

            m1.nextFit(ps, bs, p, b);
            break;
        case 3:

            m1.bestFit(ps, bs, p, b);
            break;
        case 4:

            m1.worstFit(ps, bs, p, b);
            break;
        case 5:
            cout << "\nProgram Exited" << endl;
            break;
        default:
            cout << "\nEnter valid option!!" << endl;
            break;
        }

    } while (ch != 5);

    return 0;
}