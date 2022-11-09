#include <iostream>
using namespace std;
#include <vector>


pair<int, int> getValues()  //take user input and read into pair
{
    int a, b;
    make_pair(a, b);
    cin >> a >> b;
    return make_pair(a, b);
}

int main()
{
    cout << "Lab: Input intital aPTT value followed by time of result (e.g. 43, 0316)\n";

    vector<pair<int, int>> pttVec;
    pair<int, int> pairOne;
    pairOne = getValues();

    //for (int j = 1; j <= 4; j++)
    pttVec.push_back(pairOne);
    //cout << pttVec.size();
   // cout << pttVec[0].second;

    string rep = "null";
    int i = 2;
    int rnPtt; 
    int overDue = 45;
    int currentTime = 0;
    bool correctPtt;
    bool correctTime;
    

    while (pttVec.size() < 4) { //convert numerical value to lexical for aPTTs #2-4

        if (i == 2) {
            cout << "Lab: Input second aPTT value followed by time of result.\n";
            pairOne = getValues();
            pttVec.push_back(pairOne);
            cout << "RN: Enter aPTT\n";
            cin >> rnPtt;
        }
        else
            if (i == 3) {
                cout << "Lab: Input third aPTT value followed by time of result.\n";
                pairOne = getValues();
                pttVec.push_back(pairOne);
                cout << "RN: Enter aPTT\n";
                cin >> rnPtt;
            }
            else
                if (i == 4) {
                    cout << "Lab: Input fourth aPTT value followed by time of result.\n";
                    pairOne = getValues();
                    pttVec.push_back(pairOne);
                    cout << "RN: Enter aPTT\n";
                    cin >> rnPtt;
                }
                else {
                    cout << "Invalid PTT count\n";    //catch error in looping
                }

        if (pttVec[i - 1].first != rnPtt) {
            cout << "RN: Entered aPTT does not match most recent value.\n";
            correctPtt = false;
        }
        else
            correctPtt = true;


        if (pttVec[i - 1].second + overDue < currentTime) {
            char rnConfirm;
            cout << "aPTT value resulted over 30 minutes\n" << "Is this the correct value?\n" << "Y/N";
            cin >> rnConfirm;
            switch(rnConfirm) {
            case 'N':
                cout << "Re-enter value";
                break;
            case 'Y':
                correctTime = true;
                break;
            }
        }

        if (pttVec[i-1].first == pttVec[i -2].first && pttVec[i - 1].first > 32 && pttVec[i - 1].first < 48)
            cout << "Two consecutive therapeutic results. Order AM aPTT?\n";
        else
            cout << "aPTT not therapeutic. Order aPTT in XX?\n";
        
        
        
        if (correctPtt && correctTime) {
            cout << "Bolus/Therapeutic/Hold.\n";
            if (pttVec[i - 1].first == pttVec[i - 2].first && pttVec[i - 1].first > 32 && pttVec[i - 1].first < 48)
                cout << "Two consecutive therapeutic results. Order AM aPTT?\n";
            else
                cout << "aPTT not therapeutic. Order aPTT in XX?\n";
            ++i;
        }
    }

    while (pttVec.size() > 4)

        cout << "Lab: Input "<< pttVec.size() << "th aPTT value followed by time of result.\n";
        pairOne = getValues();
        pttVec.push_back(pairOne);
        cout << "RN: Enter aPTT";
        cin >> rnPtt;


}
