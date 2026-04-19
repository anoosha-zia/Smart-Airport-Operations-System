#include<iostream>
#include<string>
#include"Flight.h"
using namespace std;

Flight::Flight(string id, string al, string org, string dest, string dt, string at, string gn) {
	flightID = id;
	airline = al;
	origin = org;
	destination = dest;
	departureTime = dt;
	arrivalTime = at;
	emergency = false;
	gateNumber = gn;
};
Flight::~Flight() {};
