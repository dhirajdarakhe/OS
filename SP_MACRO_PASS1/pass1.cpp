
// WRITTEN BY DHIRAJ DARAKHE

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class macroPass1
{

    // REQUIRED DATATYPE
    vector<string> input;
    map<string, vector<ll>> mnt;
    vector<pair<string, string>> kpdtab;
    map<string, ll> pntab;
    vector<pair<ll, string>> pntab1;
    vector<vector<string>> mdt;

public:
   

   // CONTRUCTOR TO GET INPUT
    macroPass1()
    {
        fstream file;
        string s;
        file.open("input.txt", ios::in);
        while (getline(file, s))
            input.push_back(s);
    }

    // TO MAKE ARRAY OF STRING 
    vector<string> makeWords(string read)
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

    // TO GENERATE THE OUTPUT
    void pass1()
    {
        ll is_it_macro_defination = 0;
        ll kp_size = 0;
        ll mdt_size = 0;
        for (int i = 0; i < input.size(); ++i)
        {
            vector<string> line = makeWords(input[i]);
            string macroname = "";
            

            // FIRAT LINE OF THE MACRO
            if (line[0] == "MACRO")
            {
                kp_size = kpdtab.size();
                mdt_size = mdt.size();
                is_it_macro_defination = 1;
            }
            

            // MACRO DEFINATION
            else if (is_it_macro_defination == 1)
            {
                macroname = line[0];
                is_it_macro_defination = 0;
                ll pp = line.size() - 1;
                ll kp = 0;
                for (int j = 1; j < line.size(); ++j)
                {
                    string defaultVal = "";
                    string para = "";
                    ll st = 0;
                    for (int k = 0; k < line[j].size(); ++k)
                    {
                        if (line[j][k] == '&')
                        {
                            st = 1;
                            continue;
                        }
                        if (line[j][k] == '=')
                        {
                            st = 0;
                            kp++;
                            continue;
                        }
                        if (st == 1)
                            para += line[j][k];
                        if (st == 0)
                            defaultVal += line[j][k];
                    }

                    if (st == 0)
                    {
                        kpdtab.push_back({para, defaultVal});
                    }
                    pntab[para] = j;
                    pntab1.push_back({j, para});
                    defaultVal = "";
                    para = "";
                }
                pp -= kp;
                vector<ll> mt = {pp, kp, (mdt_size + 1), (kp_size + 1)};
                mnt[macroname] = mt;
            }

            // MACRO BODY 
            else
            {
                string rname = line[0];
                vector<string> md;
                md.push_back(rname);
                for (ll k = 1; k < line.size(); ++k)
                {
                    string fname = line[k];
                    string para = "";
                    for (int j = 0; j < fname.size(); ++j)
                    {
                        if (fname[j] == '&')
                            continue;
                        para += fname[j];
                    }
                    if (pntab[para])  md.push_back("(P, " + to_string(pntab[para]) + ")");
                    else  md.push_back(para);
                }
                mdt.push_back(md);
            }
        }
    }

    // PRINT THE OUTPUTS
    void printOptput()
    {
        cout << "    MNT " << endl;
        for (auto x : mnt)
        {
            cout << x.first << " ";
            for (auto z : x.second) cout << z << " ";
            cout << endl;
        }
        cout << endl;
        cout << " KPDTAB " << endl;
        for (auto x : kpdtab)
        {
            if (x.second == "")
                cout << x.first << " "
                     << " - " << endl;
            else
                cout << x.first << " " << x.second << endl;
        }
        cout<<endl<<endl;
        cout << " PNTAB " << endl;
        for (auto x : pntab1)
        {
            if (x.first == 0)
                continue;
            if(x.first == 1) cout<<endl;
            cout<<"  " << x.second << " " << x.first << endl;
        }
        cout<<endl;
        cout << " MDT " << endl<<endl;
        for (auto x : mdt)
        {
            for (auto z : x) cout << z << " ";
            cout << endl;
        }
    }
};

// WRITTEN BY DHIRAJ DARAKHE
int main()
{
    macroPass1 p1;
    p1.pass1();
    p1.printOptput();
    return 0;
}
