#include<iostream>
#include<string>
#include"Flight.h"
using namespace std;

int main() {
	Flight f("201","uar","org","dest","dept","at","gt",status::scheduled);
	cout<<f.getArrivalTime()<<endl;
	system("pause");
	return 0;
}