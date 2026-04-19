#include<iostream>
#include<string>
#include"Flight.h"
using namespace std;

Flight::Flight(string id, string al, string org, string dest, string dt, string at, string gn,status s) {
	flightID = id;
	airline = al;
	origin = org;
	destination = dest;
	departureTime = dt;
	arrivalTime = at;
	emergency = false;
	gateNumber = gn;
	flightStatus = s;
};
Flight::~Flight() {};
//Setters
void Flight::setStatus(status s) {
	flightStatus = s;
}
void Flight::updateDepartureTime(string time) {
	departureTime = time;
}
void Flight::assignGate(string gn) {
	gateNumber = gn;
}
void Flight::setEmergency() {
	setStatus(status::emergency);
	emergency = true;
}
//Getters
string Flight::getId() {
	return flightID;
}
string Flight::getStatus() {
	switch (flightStatus) {
	case status::scheduled: return "Scheduled";
	case status::boarding: return "Boarding";
	case status::arrived: return "Arrived";
	case status::departed: return "Departed";
	case status::delayed: return "Delayed";
	case status::cancelled: return "Cancelled";
	default: return "Unknown";
	}
}
string Flight::getGate() {
	return gateNumber;
}
string Flight::getArrivalTime() {
	return arrivalTime;
}
string Flight::getDepartureTime() {
	return departureTime;
}
bool Flight::isEmergency() {
	return emergency;
}
void Flight::flightArrived() {
	setStatus(status::arrived);
}
void Flight::delayFlight(int mins) {
	string time = departureTime;
	// Extract hour and minute
	int hour = (time[0] - '0') * 10 + (time[1] - '0');
	int minute = (time[3] - '0') * 10 + (time[4] - '0');

	// Convert to total minutes
	int total = hour * 60 + minute;

	// Add delay
	total += mins;

	// Keep within 24 hours
	total = total % (24 * 60);

	// Convert back
	hour = total / 60;
	minute = total % 60;

	// Make string manually
	string newTime = "";

	newTime += char(hour / 10 + '0');
	newTime += char(hour % 10 + '0');
	newTime += ':';
	newTime += char(minute / 10 + '0');
	newTime += char(minute % 10 + '0');
	//now departure time is the new time
	departureTime = newTime;
	//set status to delayed
	setStatus(status::delayed);
}
void Flight::cancelFlight() {
	setStatus(status::cancelled);
}
void Flight::flightDeparted() {
	setStatus(status::departed);
}
void Flight::displayFlight() {
	cout << "<>------FLIGHT INFORMATION------<>" << endl;
	cout << "Flight ID: " << flightID << "\n Origin: " << origin << "\n Airline: " << airline << endl;
	cout << "Destination: " << destination << "\n Arrival time: " << arrivalTime << "\n Departure time: " << departureTime << endl;
	cout << "Assigned gate: " << gateNumber << "\n Current Status: " <<getStatus() << endl;
}

