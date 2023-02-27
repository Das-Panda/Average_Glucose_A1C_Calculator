#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath> // added for round()
using namespace std;

int main() {
    ifstream inputFile("glucose.txt"); // open input file
    vector<pair<string, int>> glucoseData; // vector to store glucose data
    string line;
    while (getline(inputFile, line)) { // read line by line
        istringstream iss(line);
        string date;
        int glucose;
        iss >> date >> glucose;
        glucoseData.push_back(make_pair(date, glucose)); // store date and glucose as a pair
    }
    inputFile.close(); // close input file

    int totalGlucose = 0;
    for (auto data : glucoseData) {
        totalGlucose += data.second; // add up all glucose values
    }
    double avgGlucose = (double) totalGlucose / glucoseData.size(); // calculate average glucose
    int roundedAvgGlucose = round(avgGlucose); // round to the nearest whole number

    double a1c = (roundedAvgGlucose + 46.7) / 28.7; // calculate A1C
    double roundedA1C = round(a1c * 10) / 10.0; // round to the first decimal

    cout << "Your Estimated Average Glucose(mg/dL) is: " << roundedAvgGlucose << endl;
    cout << "Your Estimated A1C(%) is: " << roundedA1C << endl;
    cout << "Per The American Diabetes Association, your A1C indicates that you would be considered ";

    if (roundedA1C < 5.7) {
        cout << "Normal.";
    } else if (roundedA1C >= 5.8 && roundedA1C <= 6.5) {
        cout << "Pre-diabetic.";
    } else {
        cout << "Diabetic.";
    }
    cout << endl;

    return 0;
}
