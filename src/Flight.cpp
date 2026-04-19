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

