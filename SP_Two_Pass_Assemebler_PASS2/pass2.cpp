

// Dhiraj Darakahe

#include <bits/stdc++.h>
using namespace std;
int strtoint(string s)
{
    int num = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        num *= 10;
        num += (s[i] - '0');
    }
    return num;
}
class Pass2
{
    vector<pair<string, int>> systb;
    vector<pair<int, int>> littb;
    vector<string> word;
    int lc;
    bool flag;
    int sudoLC;

public:
    Pass2()
    {
        lc = 0;
        flag = false;
        sudoLC = 0;
        fstream file;
        string s;
        file.open("systab.txt", ios::in);
        while (getline(file, s))
            systb.push_back({input2(s)[0], strtoint(input2(s)[1])});
        file.close();
        file.open("littab.txt", ios::in);
        while (getline(file, s))
            littb.push_back({strtoint(input2(s)[0]), strtoint(input2(s)[1])});
        file.close();
    }
    vector<string> input2(string read)
    {
        vector<string> word;
        string s1 = "";
        for (int i = 0; i < read.size(); ++i)
        {
            if (read[i] == ' ')
            {
                word.push_back(s1);
                s1 = "";
                continue;
            }
            s1 += read[i];
        }
        word.push_back(s1);
        return word;
    }
    void printTAB()
    {
        cout << "Literal Table \n"
             << endl;
        for (int i = 0; i < littb.size(); ++i)
            cout << i + 1 << " ) " << littb[i].first << " " << littb[i].second << endl;
        cout << endl;
        cout << "SYSTEM Table \n"
             << endl;
        for (int i = 0; i < systb.size(); ++i)
            cout << i + 1 << " ) " << systb[i].first << " " << systb[i].second << endl;
    }
    void MachineCode()
    {
        fstream file;
        string s;
        file.open("pass1.txt", ios::in);
        while (getline(file, s))
        {
            word = input2(s);
            for (int i = 0; i < word.size(); ++i)
                cout << word[i] << " ";
            cout << " ";
            if (word.size() == 0)
                return;
            if (word[0] == "(AD,01)")
            {
                lc = strtoint(word[1].substr(3, 3)); // '(c,200)'
                cout << endl;
                continue;
            }
            if (word[0] == "(AD,02)")
            {
                cout << "           NO MACHINE CODE FOR (AD,02) ";
                cout << endl;
                continue;
            }
            if (word[0] == "(AD,03)")
            {
                flag = true;
                if (word[1][1] == 'L')
                    sudoLC = littb[strtoint(word[1].substr(3, 2)) - 1].second;
                else
                    sudoLC = systb[strtoint(word[1].substr(3, 2)) - 1].second;
                sudoLC += (int)(word[1][word[1].size() - 1] - '0');
                lc = sudoLC;
                cout << "  NO MACHINE CODE FOR (AD,03) ";
                cout << endl;
                continue;
            }
            if (word[0] == "(AD,04)")
            {
                cout << "           NO MACHINE CODE FOR (AD,04) ";
                cout << endl;
                continue;
            }
            if (word[0] == "(AD,05)")
            {
                cout << "           NO MACHINE CODE FOR (AD,05) ";
                cout << endl;
                continue;
            }

            if (word[0] == "(IS,00)")
            {
                cout << "           " << lc << " " << 00 << " " << 0 << " " << 000;
            }
            if (word[0] == "(DL,01)")
            {
                cout << "     " << lc << "  " << 00 << " " << 0 << " " << 00 << word[1][3]; // (c,2)
            }
            if (word[0] == "(DL,02)")
            {
                cout << "     " << lc;
                lc += strtoint(word[1].substr(3, 1)); // '(c,2)'
                continue;
            }
            if (word[0].substr(1, 2) == "IS" && word[0].substr(4, 2) != "00")
            {
                cout << lc << "  " << word[0].substr(4, 2) << " " << word[1][1] << " ";
                if (word[2][1] == 'L')
                    cout << littb[strtoint(word[2].substr(3, 2)) - 1].second;
                else
                    cout << systb[strtoint(word[2].substr(3, 2)) - 1].second;
            }
            lc++;
            cout << endl;
        }
    }
};
int main()
{

    Pass2 p2;
    cout << "\n\n";
    p2.printTAB();
    cout << "\n\n";
    cout << "        MACHINE CODE \n\n";
    p2.MachineCode();
    cout << "\n\n\n\n";
    return 0;
}

// output

// Literal Table

// 1 ) 5 211
// 2 ) 1 212
// 3 ) 1 219

// SYSTEM Table

// 1 ) A 217
// 2 ) LOOP 202
// 3 ) B 218
// 4 ) NEXT 214
// 5 ) BACK 202
// 6 ) LAST 216

//         MACHINE CODE

// (AD,01) (C,200)
// (IS,04) (1) (L,01)  200  04 1 211
// (IS,05) (1) (S,01)  201  05 1 217
// (IS,04) (1) (S,01)  202  04 1 217
// (IS,04) (3) (S,03)  203  04 3 218
// (IS,01) (3) (L,02)  204  01 3 212
// (IS,04) (1) (S,01)  205  04 1 217
// (IS,04) (3) (S,03)  206  04 3 218
// (IS,04) (1) (S,01)  207  04 1 217
// (IS,04) (3) (S,03)  208  04 3 218
// (IS,04) (1) (S,01)  209  04 1 217
// (IS,07) (6) (S,04)  210  07 6 214
// (DL,01) (C,5)       211  0 0 05
// (DL,01) (C,1)       212  0 0 01
// (IS,04) (1) (S,01)  213  04 1 217
// (IS,02) (1) (L,03)  214  02 1 219
// (IS,07) (1) (S,05)  215  07 1 202
// (IS,00)             216 0 0 0
// (AD,03) (S,02)+2    NO MACHINE CODE FOR (AD,03)
// (IS,03) (3) (S,03)  204  03 3 218
// (AD,03) (S,06)+1    NO MACHINE CODE FOR (AD,03)
// (DL,02) (C,1)       217
// (DL,02) (C,1)       218
// (AD,02)             NO MACHINE CODE FOR (AD,02)
// (DL,01) (C,1)       219  0 0 01
