#pragma once
#include<string>
using namespace std;

enum class status { scheduled, boarding, arrived, departed, delayed, cancelled,emergency };
class Flight {
	string flightID; //each flight has a unique flight id
	string airline;// the name of airline to which flight is attatched
	string origin;
	string destination;
	string departureTime;
	string arrivalTime;
	bool emergency;
	string gateNumber;//assigned gate to the flight-should be strictly followed to avoid mess
	status flightStatus;
private:
	void setStatus(status s);
public:
	Flight(string id,string al,string org,string dest,string dt,string at,string gn,status s);
	~Flight();
		//Accessors and mutators
//Setters
	void updateDepartureTime(string time);
	void assignGate(string gn);
	void setEmergency();
//Getters
	string getId();
	string getStatus();
	string getGate();
	string getArrivalTime();
	string getDepartureTime();
	bool isEmergency();
//other important functions
	void flightArrived();
	void delayFlight(int mins);
	void cancelFlight();
	void flightDeparted();
	void displayFlight();
};