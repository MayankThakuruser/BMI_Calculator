#include <iostream>
#include <string>
using namespace std;

struct Measurment {
    double weight{ 0 };
    double height{ 0 }; // fixed: was 1, caused bmi to equal weight when input failed
    int age{};
    string gender{};
}; // used struct instead of class to make information public as default

void personalInformation(Measurment& m)
{
    cout << "Enter Your Gender = ";
    cin >> m.gender;
    cout << "Enter your age = ";
    cin >> m.age;
    cout << "Enter your weight(kg) = ";
    cin >> m.weight;
    cout << "Enter your height (m) = ";
    cin >> m.height;
}
double calculateBMR(const Measurment& m)
{

    double BMR{};
    if (m.gender == "Male" || m.gender == "male") // fixed: was checking || "male" which always returns true, needed to compare m.gender again
        BMR = (10 * m.weight) + (6.25 * m.height * 100) - (5 * m.age) + 5;
    else if (m.gender == "Female" || m.gender == "female") // same fix here for female check
        BMR = (10 * m.weight) + (6.25 * m.height * 100) - (5 * m.age) - 161;

    return BMR;
}

double calculateTDEE(double bmrValue)
{
    cout << "Excercise intensity = Sedentary(s) or Lightly active(l) or Moderataly active(m) or Very active(v) =";
    string intensity{};
    double tdee{};
    cin >> intensity;
    if (intensity == "s")
        tdee = bmrValue * 1.2;
    else if (intensity == "l")
        tdee = bmrValue * 1.375;
    else if (intensity == "m")
        tdee = bmrValue * 1.55;
    else if (intensity == "v")
        tdee = bmrValue * 1.725;
    return tdee;
}

void calculateCalorie(double tdee, double bmi) {
    cout << "\n--- Your Nutritional Report ---\n";
    cout << "Your Maintenance Calories: " << tdee << " kcal/day" << endl;

    if (bmi < 18.5) {
        cout << "To reach a healthy status, you should eat: " << tdee + 500 << " kcal (Bulking)";
    }
    else if (bmi >= 25.0) {
        cout << "To reach a healthy status, you should eat: " << tdee - 500 << " kcal (Cutting)";
    }
    else {
        cout << "You are doing great! Stick to " << tdee << " kcal.";
    }
}



void checkWeightStatus(double bmi)
{
    if (bmi < 18.5)
        cout << "Stop the gooning bro";
    else if (bmi >= 18.5 && bmi <= 24.9) // changed > to >= and < to <= so exact values like 18.5 or 24.9 dont fall through
        cout << "Stand Proud, You are Healthy";
    else if (bmi >= 25.0 && bmi <= 29.9) // same deal here, >= and <= instead of > and 
        cout << " Control your mouth Merk ";
    else if (bmi >= 30)
        cout << "Just JUmpp the f*k off dude";

}
int main() {
    Measurment user;
    personalInformation(user); // Input data only ONCE

    double bmi = user.weight / (user.height * user.height); // this calculates correctly now that height isnt stuck at 1
    double bmr = calculateBMR(user); // Uses the data from 'user'
    double tdee = calculateTDEE(bmr);

    checkWeightStatus(bmi);
    cout << "\nYour BMI = " << bmi << endl;
    calculateCalorie(tdee, bmi); // Final output

    return 0;
}
