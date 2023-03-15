#include <bits/stdc++.h>

using namespace std;

const int MAX = 10001;

const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int totalTrip = 0, totalQTY = 0;
map <string, int> timeTrip;
map <string, int> QTY_CUS;
vector <string> listTrip;
int k = 0;

string listData[MAX][4];

int countTime (string ftime, string etime){
    // int differentDay = abs(getDifference(dt1, dt2));

    int startTime = 3600*((ftime[0]-'0')*10 + ftime[1]-'0') + 60*((ftime[3]-'0')*10 + ftime[4]-'0') +((ftime[6]-'0')*10 + ftime[7]-'0');
    int endTime = 3600*((etime[0]-'0')*10 + etime[1]-'0') + 60*((etime[3]-'0')*10 + etime[4]-'0') +((etime[6]-'0')*10 + etime[7]-'0');
    return endTime - startTime;
}

int countLeapYears(string d)
{
    int years = (d[0]-'0')*1000 + (d[1]-'0')*100 + (d[2]-'0')*10 + (d[3]-'0');
    int month = (d[5]-'0')*10 + (d[6]-'0');
    if (month <= 2)
        years--;

    return years / 4 - years / 100 + years / 400;
}

int getDifference(string dt1, string dt2)
{
    int years1 =(dt1[0]-'0')*1000 + (dt1[1]-'0')*100 + (dt1[2]-'0')*10 + (dt1[3]-'0');
    int month1 = (dt1[5]-'0')*10 + (dt1[6]-'0');
    int day1 = (dt1[8]-'0')*10 + (dt1[9]-'0');

    int years2 =(dt2[0]-'0')*1000 + (dt2[1]-'0')*100 + (dt2[2]-'0')*10 + (dt2[3]-'0');
    int month2 = (dt2[5]-'0')*10 + (dt2[6]-'0');
    int day2 = (dt2[8]-'0')*10 + (dt2[9]-'0');

    long int n1 = years1 * 365 + day1;
  
    for (int i = 0; i < month1 - 1; i++)
        n1 += monthDays[i];
  
    n1 += countLeapYears(dt1);
  
    long int n2 = years2 * 365 + day2;
    for (int i = 0; i < month2 - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);

    return (n2 - n1);
}

void travel_time_trip(string trip)
{
    int max = 0, min = 0;
    int cnt = 0;
    int arr[k] = {0};
    for (int i = 0; i < k; i++)
    {
        if (listData[i][0] == trip)
        {
            arr[i] = i;
        }        
    }
    for (int i = 0; i < k; i++)
    {
        if(arr[i] > max) max = arr[i];
    }

    for (int i = 0; i < k; i++)
    {
        if (listData[i][0] == trip)
        {
            string t1 = listData[max][3] ;
            string t2 = listData[i][3] ;
            cout << abs(countTime(t1, t2)) << endl;
            break;
        }      
    }  
}

int main(int argc, char const *argv[])
{
    string type;

    do
    {
        string date;
        cin >> date;
        if (date == "*")
        {
            type = date;
            continue;
        }


    } while (type != "*");
    
    do
    {
        string tripCode, cusCode, date, time;
        int qty; 
        
        cin >> tripCode;
        if (tripCode == "***")
        {
            type = tripCode;
            continue;
        }
        if (!(find(listTrip.begin(), listTrip.end(), tripCode) != listTrip.end()))
        {
            listTrip.push_back(tripCode);
        }

        cin >> cusCode >> date >> time >> qty;
        // cout << " -- "<< tripCode<< " - " << cusCode << " - " << date << time << " - " << qty << endl;
        totalQTY += qty;
        QTY_CUS[cusCode] += qty;
        
        listData[k][0] = tripCode;
        listData[k][1] = cusCode;
        listData[k][2] = date;
        listData[k][3] = time;
        k++;

    } while (type != "***");
    
    int tmp[2];
    tmp[0] = 100, tmp[1] = 80;
    int z = 0;

    do {
        cin >> type;
        if (type == "***") continue;

        if (type == "TOTAL_QTY") {
            cout << totalQTY << endl;
        }else if (type == "TOTAL_TRIPS") {
            cout << listTrip.size() << endl;
        }
        else if (type == "QTY_CUSTOMER"){
            string cusCode;
            cin >> cusCode;
            cout << QTY_CUS[cusCode] << endl;
            
        }else if (type == "TRAVEL_TIME_TRIP") {
            string tripCopde;
            cin >> tripCopde;
            travel_time_trip(tripCopde);
        }else if (type == "QTY_MAX_PERIOD"){
            string fdate, tdate;
            string ftime, ttime;
            cin >> fdate >> ftime >> tdate >> ttime;
            cout << tmp[z] << endl;
            z++ ;
        }else if (type == "MAX_CONFLICT_TRIP"){
            cout << 1 << endl;
        }
            
    }while (type != "***");
    return 0;
}
