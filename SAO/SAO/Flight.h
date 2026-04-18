#pragma once
#include<string>
using namespace std;
class Flight {
	string flightID; //each flight has a unique flight id
	string airline;// the name of airline to which flight is attatched
	string origin;
	string destination;
	string departureTime;
	string arrivalTime;
	bool emergency;
	string gateNumber;//assigned gate to the flight-should be strictly followed to avoid mess
	enum class status { scheduled, boarding, arrived, departed, delayed, cancelled };
public:
	Flight(string id,string al,string org,string dest,string dt,string at,string gn);
	~Flight();
		//Accessors and mutators
//Setters
	void setStatus(string status);
	void updateDepartureTime(string time);
	void assignGate(string gateNumber);
	void setEmergency();
//Getters
	string getId();
	string getStatus();
	string getGate();
	string getArrivalTime();
	string getDepartureTime();
	bool isEmergency();



};