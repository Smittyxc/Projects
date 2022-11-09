#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Climb {
public:
    double level;
    string rock;
    char style;

    Climb(string name, double grade, char type)
        :rock(name), level(grade), style(type) {} //style(type)
};

Climb climb_get() {    
    char climbType;
    double grade;
    string name;
    char type;
    
    getline(cin, name, '.');

    cin >> climbType;
  //  cout << climbType;
    switch (climbType) {
    case 'V':
        cin >> grade;
        type = 'V';
        break;
    case '5':
        cin.putback(climbType);
        cin >> grade;
        type = 'S';
        break;
    default:
        cout << "Only accepting YDS and Hueco grading.\n" << climbType;
        break;
    }
    return Climb(name, grade, type);
}

vector<Climb> vectClimb;

void recall() {
    int i;                         //narrow scope?
    if(vectClimb.size() == 0) {                //checks vector for minimal input
        cout << "No climbs entered yet";
     
    }
    cout << "Total sends = " << vectClimb.size() << "\n";
    for (i = 0; i <= vectClimb.size() - 1; i++) {
        cout << vectClimb[i].rock;
        if (vectClimb[i].style == 'V') {
            cout << ", V" << vectClimb[i].level << "\n";
        }
        else if (vectClimb[i].style == 'S') {
            cout << ", " << vectClimb[i].level << "\n";
        }
        else {
            cout << "error in recall.";
        }
    }
 }

int main() {
    bool cont = true;
    char quit;
   
   
    cout << "Welcome to your climbing log, gumby.\n";
    cout << "Enter name and grade of your send (Name. Grade)\n";
    while (cont) {
        Climb climb1 = climb_get();
        vectClimb.push_back(climb1);
    
        cout << "Enter - to quit, + to recall sends.\n";
        cin >> quit;
        switch (quit) {
        case '-':
            cont = false;
            break;
        case '+':
            recall();
            cout << "To quit enter - or enter additional sends.";
            break;
        default:
            cin.putback(quit);
            break;

        }
    }
    
    return 0;
}