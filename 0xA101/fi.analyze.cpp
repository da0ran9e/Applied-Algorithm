#include<bits/stdc++.h>
using namespace std;



int convert_to_seconds(string time)
{
	int times = 3600*((time[0]-'0')*10+(time[1]-'0'))+60*((time[3]-'0')*10+(time[4]-'0'))+(time[6]-'0')*10+(time[7]-'0');
	return times;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	string query;
	string dates, trip_code, customer_code, date, time; 
	int qty;
	int total_qty=0;
	string c_code, t_code, fdate, edate, ftime, etime;
	unordered_map <string, int> qty_customer;
	map <string, int> tvl_time;
	int total_trips=0;
	//vector<string>trips;
	set<string> Trips;

	do{
		cin >> dates;
		if (dates == "*") continue;
		//cin >> dates;

	}
	while(dates!="*");

	do{
		cin >> trip_code;
		if (trip_code == "***") continue;
		cin >> customer_code >> date >> time >> qty;
		total_qty = total_qty + qty;
		
		Trips.insert(trip_code);
		// trips.push_back(trip_code);
		// if (find(trips.begin(), trips.end(), trip_code) == trips.end()-1) {
        //     total_trips++;
        // }
		// qty_customer[customer_code]=qty_customer[customer_code]+qty;
		// // tvl_time[trip_code]=tvl_time[trip_code]+convert_to_seconds(time);
	}
	while(trip_code != "***");
	
	do{
		cin >> query;
		if (query=="***") continue;
		
		if(query=="TOTAL_QTY")
		{
			cout << total_qty << endl;
		}
		else if(query=="QTY_CUSTOMER"){
			cin >> c_code;
			cout << qty_customer[c_code] << endl;
		}
		else if(query=="QTY_MAX_PERIOD"){
			cin >> fdate >> ftime >> edate >> etime;

		}
		else if(query=="TOTAL_TRIPS")
		{
			cout << Trips.size() << endl;
		}
		else if(query=="TRAVEL_TIME_TRIP")
		{
			cin >> t_code;
		}
		else if(query=="MAX_CONFLICT_TRIPS")
		{

		}
	}
	while(query!="***");
	return 0;
}
