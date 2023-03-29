#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int convert_to_seconds(string time) {
    int times = 3600*((time[0]-'0')*10+(time[1]-'0'))+60*((time[3]-'0')*10+(time[4]-'0'))+(time[6]-'0')*10+(time[7]-'0');
    return times;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string D, C;
    string query;
    string dates, trip_code, customer_code, date, time;
    int qty;
    int total_qty = 0;
    string c_code, t_code, fdate, edate, ftime, etime;
    map<string, int> qty_customer;
    map<string, int> tvl_time;
    int total_trips = 0;
    vector<string> trips;

    do {
        cin >> D;
        if (D == "*") continue;
        cin >> dates;
    } while(D!="*");

    do {
        cin >> C;
        if (C == "***") continue;
        cin >> trip_code >> customer_code >> date >> time >> qty;

        total_qty = total_qty + qty;

        if (find(trips.begin(), trips.end(), trip_code) == trips.end()) {
            total_trips++;
            trips.push_back(trip_code);
        }
        qty_customer[customer_code] = qty_customer[customer_code] + qty;

        // tvl_time[trip_code]=tvl_time[trip_code]+convert_to_seconds(time);
    } while(C != "***");

    do {
        cin >> query;
        if (query == "***") continue;

        if(query == "TOTAL_QTY") {
            cout << total_qty << endl;
        }
        else if(query == "QTY_CUSTOMER") {
            cin >> c_code;
            cout << qty_customer[c_code] << endl;
        }
        else if(query == "QTY_MAX_PERIOD") {
            cin >> fdate >> ftime >> edate >> etime;
        }
        else if(query == "TOTAL_TRIPS") {
            cout << total_trips << endl;
        }
        else if(query == "TRAVEL_TIME_TRIP") {
            cin >> t_code;
        }
        else if(query == "MAX_CONFLICT_TRIPS") {
        }
    } while(query != "***");

    return 0;
}
