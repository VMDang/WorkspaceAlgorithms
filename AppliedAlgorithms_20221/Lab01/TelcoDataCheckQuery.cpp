#include<iostream>
#include<map>
#include<queue>
using namespace std;

int countFailePhone=0;
int number_total_calls=0;
map<string,int> number_calls_from;
map<string,int> time_calls;
queue<string>query;
queue<string>phone_numbs;


bool checkPhone(string phone){
	if(phone.length() != 10) return false;
	for(int i = 0; i < phone.length(); i++){
		if(phone[i]<'0' || phone[i]>'9') {
			return false; 
		}
	}
	return true;
}

int countSecond(string start, string end){
	int startTime = 3600*((start[0]-'0')*10 + (start[1]-'0')) + 60*((start[3]-'0')*10 + (start[4]-'0')) + ((start[6]-'0')*10 + (start[7]-'0'));
	int endTime = 3600*((end[0]-'0')*10 + (end[1]-'0')) + 60*((end[3]-'0')*10 + (end[4]-'0')) + ((end[6]-'0')*10 + (end[7]-'0'));
	return endTime - startTime;
}
int main(){
	string word ; 
	do{	
		string phone1;
		string phone2;
		string date1;
		string time1;
		string time2;
		
		cin >> word;
		if(word == "#") continue;
		else{
			cin >> phone1 >> phone2	>>	date1 >> time1 >> time2;
			if( !(checkPhone(phone1) && checkPhone(phone2)) ) {
				countFailePhone++;
			}
			
			number_total_calls++ ;
			
			auto find = number_calls_from.find(phone1);
			
			if(find == number_calls_from.end()){
				number_calls_from.insert({phone1, 1});
				int time = countSecond(time1, time2);
				time_calls.insert({phone1, time});
			}else{
				find->second = find->second +1;
				time_calls[phone1] += countSecond(time1,time2);
			}
		}
	}while(word!="#");
	
	
	string ch;
	string phone;
	do{
		cin >> ch;
		if(ch=="#") continue;
		else{
			
			query.push(ch);
			if(ch == "?number_calls_from") {
				cin >> phone;
				phone_numbs.push(phone);
			}
			if(ch == "?count_time_calls_from"){
				cin >> phone;
				phone_numbs.push(phone);
			}
		}
	}while(ch!="#");
	
	while(!query.empty()){
		string ch = query.front();
		query.pop();

		string phone;

		if(ch == "?check_phone_number" ) {
			cout <<(countFailePhone == 0 ? "1" : "" ) << endl;
		}

		if(ch == "?number_calls_from") {
			phone = phone_numbs.front();
			phone_numbs.pop();
			cout<< number_calls_from[phone] << endl;
		}

		if(ch == "?number_total_calls"){
			cout << number_total_calls << endl;
		}
		
		if(ch == "?count_time_calls_from"){
			phone = phone_numbs.front();
			phone_numbs.pop();
			cout << time_calls[phone] << endl;
		}
	}
	return 0;
}
