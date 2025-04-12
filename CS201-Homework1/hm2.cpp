#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "strutils.h"

using namespace std;

void displayResults(double difference, double totalPoint, double goalPoint, double assistPoint, double nutmegPoint) {
    cout << "\nFrom scoring goals, you collected " << goalPoint << " points." << endl;
    cout << "From making assists, you collected " << assistPoint << " points." << endl;
    cout << "From nutmegs, you collected " << nutmegPoint << " points." << endl;
    cout << "You collected " << totalPoint << " points." << endl;
    if (difference == 0)
        cout << "Congratulations! You have reached your goal!" << endl;
    else if (difference > 0)
        cout << "You have surpassed your goal! You have extra " << difference << " points :)" << endl;
    else
        cout << "You did not reach your goal by " << -difference << " points." << endl;
}

double calculateScore(int league, const string& exercise) {
    if (exercise == "goal") {
        if (league >= 4 && league < 6) { return 4.0; }
        else return 6.5;
    }
    else if (exercise == "assist") {
        if (league >= 4 && league < 11) { return 9.0; }
        else return 12.5;
    }
    else if (exercise == "nutmeg") {
        if (league >= 4 && league < 20) { return 6.0; }
        else if (league < 25) { return 8.0; }
        else return 10.5;
    }
    return 0.0;
}

void computeResults(int matches, int goal, int league, int goalCount, int assistCount, int nutmegCount) {
    double goalPoint = matches * goalCount * calculateScore(league, "goal");
    double assistPoint = matches * assistCount * calculateScore(league, "assist");
    double nutmegPoint = matches * nutmegCount * calculateScore(league, "nutmeg");
    double totalPoint = goalPoint + assistPoint + nutmegPoint;
    double difference = totalPoint - goal;
    displayResults(difference, totalPoint, goalPoint, assistPoint, nutmegPoint);
}

void getInput(const string& username) {
    int matches, league, goalCount, assistCount, nutmegCount, goal;

    cin >> matches;
    while (matches < 0) {
        cout << "Number of matches out of range!" << endl;
        cout << username << ", please enter your number of matches played: ";
        cin >> matches;
    }

    cout << username << ", please enter your league: ";
    cin >> league;
    while (league < 4 || league > 30) {
        cout << "League out of range!" << endl;
        cout << username << ", please enter your league: ";
        cin >> league;
    }

    cout << username << ", how many times did you score a goal: ";
    cin >> goalCount;
    while (goalCount < 0) {
        cout << "Times out of range!" << endl;
        cout << username << ", how many times did you score a goal: ";
        cin >> goalCount;
    }

    cout << username << ", how many times did you make an assist: ";
    cin >> assistCount;
    while (assistCount < 0) {
        cout << "Times out of range!" << endl;
        cout << username << ", how many times did you make an assist: ";
        cin >> assistCount;
    }

    cout << username << ", how many times did you nutmeg an opponent: ";
    cin >> nutmegCount;
    while (nutmegCount < 0) {
        cout << "Times out of range!" << endl;
        cout << username << ", how many times did you nutmeg an opponent: ";
        cin >> nutmegCount;
    }

    cout << username << ", please enter your weekly point goal: ";
    cin >> goal;

    computeResults(matches, goal, league, goalCount, assistCount, nutmegCount);
}

void makeUsername(const string& sentence) {
    string surname, name, birthdate;
    stringstream ss(sentence);
    getline(ss, surname, ',');
    getline(ss, name, ',');
    getline(ss, birthdate);

    ToLower(surname);
    ToLower(name);

    int dash1 = birthdate.find('-');
    int dash2 = birthdate.find('-', dash1 + 1);
    int birthMonth = atoi(birthdate.substr(0, dash1).c_str());
    int birthDay = atoi(birthdate.substr(dash1 + 1, dash2 - dash1 - 1).c_str());
    int birthYear = atoi(birthdate.substr(dash2 + 1).c_str());

    int age = 2025 - birthYear;
    if (birthMonth > 4 || (birthMonth == 4 && birthDay > 14)) age--;

    string username = name + surname + itoa(age);
    cout << "Welcome " << username << ", please enter your number of matches played: ";
    getInput(username);
}

int main() {
    string sentence;
    cout << "Please enter your information: ";
    getline(cin, sentence);
    makeUsername(sentence);
    return 0;
}