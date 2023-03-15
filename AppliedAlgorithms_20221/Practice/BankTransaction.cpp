#include <bits/stdc++.h>

using namespace std;

int totalTransaction = 0;
int totalMoney = 0;
map <string, int> moneyFrAcc;
vector <string> listAcc;
vector <string> logAcc;

int inspect_cycle(string Acc, int k)
{
    int cnt = 0;
    for (int i = 0; i < logAcc.size(); i++)
    {
        if (logAcc[i] == Acc)
        {
           for (int j = i; j < k; j++)
           {
                if (logAcc[j] == Acc)
                {
                    cnt++;
                }
           }

           if (cnt == k)
           {
                return 1;
           }
           else cnt = 0;
           
        } 
    }

    return 0;
}

int main()
{
    string type;
    do
    {
        string frAcc, toAcc, time, atm;
        int money;
        cin >> frAcc ;
        if (frAcc == "#")
        {
            type = frAcc;
            continue;
        }
        logAcc.push_back(frAcc);
        cin >> toAcc >> money >> time >> atm;
        // cout << "from:"<< frAcc <<" - to:" << toAcc << " - money: " << money << endl;
        if (!(find(listAcc.begin(), listAcc.end(), frAcc) != listAcc.end()))
        {
            listAcc.push_back(frAcc);
        }
        if (!(find(listAcc.begin(), listAcc.end(), toAcc) != listAcc.end()))
        {
            listAcc.push_back(toAcc);
        }
        totalTransaction++;
        totalMoney += money;
        moneyFrAcc[frAcc] += money;
    } while (type != "#");
    do
    {
        cin >> type;
        if(type == "#") continue;

        if (type == "?number_transactions")
        {
            cout << totalTransaction << endl;
        }else if (type == "?total_money_transaction")
        {
            cout << totalMoney << endl;
        }else if (type == "?list_sorted_accounts")
        {
            sort(listAcc.begin(), listAcc.end());
            for (auto Acc : listAcc)
            {
                cout << Acc << " ";
            }
            cout << endl;
        }else if (type == "?total_money_transaction_from")
        {
            string Acc;
            cin >> Acc;
            cout << moneyFrAcc[Acc] << endl;
        }else if (type == "?inspect_cycle")
        {
            string Acc;
            int k;
            cin >> Acc >> k;
            cout << inspect_cycle(Acc, k) << endl;        
        }
        
    } while (type != "#");
    
    return 0;
}
/*
T000010010 T000010020 1000 10:20:30 ATM1
T000010010 T000010030 2000 10:02:30 ATM2
T000010010 T000010040 1500 09:23:30 ATM1
T000010020 T000010030 3000 08:20:31 ATM1
T000010030 T000010010 4000 12:40:00 ATM2
T000010040 T000010010 2000 10:30:00 ATM1
T000010020 T000010040 3000 08:20:31 ATM1
T000010040 T000010030 2000 11:30:00 ATM1
T000010040 T000010030 1000 18:30:00 ATM1
#
?number_transactions
?total_money_transaction
?list_sorted_accounts
?total_money_transaction_from T000010010
?inspect_cycle T000010010 3
#
*/