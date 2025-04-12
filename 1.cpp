#include <iostream>
using namespace std;



/*  (downloadtime.cpp)
    int main() {
	double fsize, cspeed ;
	int hour, minute, second,time;
	cout << "please enter the file size and connection speed: ";
	cin >> fsize >> cspeed;
	// speed input bits per second
	time = fsize / (cspeed * 1024 * 1024 * 8);
	hour = time / 3600;
	minute = (time % 3600) / 60;
	second = time % 60;
	cout << hour << " Hour(s) " << minute << " Minute(s) " << second << " Second(s)" << endl;
	return 0;

}

*/

/*  (bmi.pp)
    int main() {
	double weight, height;
	double bmi;
	cout << "please enter your weight and your height";
	cin >> weight >> height;
	bmi = weight / (height * height);
	cout << "your bmi is: " << bmi;
	return 0;
}
*/


int main() {
	//time untel they meet
	//meeting point towards each other
	string location1, location2;
	float distance, velocity1, velocity2 ,time,distanceA , distanceB;
	cout << "please enter the locations of cars: ";
	cin >> location1 >> location2;
	cout << "please enter the speeds of both cars: ";
	cin >> velocity1 >> velocity2;
	cout << "please enter the distance";
	cin >> distance;
	time = distance / (velocity1 + velocity2);
	distanceA = velocity1 * time;
	distanceB = velocity2 * time;
	cout << "distance from" << location1 << distanceA << "distance from " << location2 << distanceB;
	return 0;

}