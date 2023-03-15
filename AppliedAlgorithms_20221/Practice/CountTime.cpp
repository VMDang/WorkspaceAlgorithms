#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Different 2 time
 * 
 * @param ftime     || format HH:mm::s
 * @param etime     || format HH:mm::s
 * @return second (int)
 */
int countTime (string ftime, string etime){
    int startTime = 3600*((ftime[0]-'0')*10 + ftime[1]-'0') + 60*((ftime[3]-'0')*10 + ftime[4]-'0') +((ftime[6]-'0')*10 + ftime[7]-'0');
    int endTime = 3600*((etime[0]-'0')*10 + etime[1]-'0') + 60*((etime[3]-'0')*10 + etime[4]-'0') +((etime[6]-'0')*10 + etime[7]-'0');
    return endTime - startTime;
}


const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int countLeapYears(string d)
{
    int years = (d[0]-'0')*1000 + (d[1]-'0')*100 + (d[2]-'0')*10 + (d[3]-'0');
    int month = (d[5]-'0')*10 + (d[6]-'0');
    if (month <= 2)
        years--;

    return years / 4 
           - years / 100
           + years / 400;
}

/**
 * @brief Get the Difference 2 date
 * 
 * @param dt1   format|YYYY-MM-DD
 * @param dt2   format|YYYY-MM-DD
 * @return day (int) 
 */
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
//84200
//24000
int main(int argc, char const *argv[])
{
    string dt1 = "17:35:07";   
    string dt2 = "24:15:07";   
    cout << countTime(dt1, dt2);
    return 0;
}
