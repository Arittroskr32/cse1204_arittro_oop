#include<bits/stdc++.h>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Member{
public:
    string mobileNo;
    string name;
    double amount;
    string pin;
    Member(string mobile, string n, double amt, string p): mobileNo(mobile), name(n), amount(amt), pin(p) {}
};

class History{
public:
    int Transaction_id_no;
    string customer_mobile_no;
    string Transacyion_type;
    double amount;
    double balance; 
    time_t Transaction_time;
    History(int id, string mobile, string type, double amt, double bal)
        : Transaction_id_no(id), customer_mobile_no(mobile), Transacyion_type(type), amount(amt), balance(bal){
        Transaction_time = time(nullptr);
    }
};


class MyCash{ 
public:
    vector<Member> member_list;
    vector<History> transactionHistory;
    Member* current_user = nullptr;
    //generate OTP
    string generateOTP(){
        srand(time(nullptr));
        int otp = rand() % 9000 + 1000;
        return to_string(otp);
    }
    // member registration
    void registerMember(){
        string mobile, name, pin;
        cout << "Enter Mobile No. (11-digit): ";
        cin >> mobile;
    // Checking duplicate member
    for (const Member& member : member_list) {
        if (member.mobileNo == mobile) {
            cout << "Member already exists." << endl;
            return;
        }
    }
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter pin (5-digit): ";
    cin >> pin;

    cout << "Reconfirm pin: ";
    string confirmPin;
    cin >> confirmPin;

    if (pin != confirmPin) {
        cout << "Pins is not maching. Registration failed." << endl;
        return;
    }

    time_t registrationTime = time(nullptr);
    string otp = generateOTP();

    cout << "Enter Your OTP: " << otp << endl;
    cout << "You have 2 minutes to enter the OTP." << endl;
    time_t currentTime;
    string enteredOTP;
    do {
        currentTime = time(nullptr);
        if (currentTime - registrationTime > 120) {
            cout << "OTP time has expired. Registration failed." << endl;
            return;
        }
        cout << "Enter OTP: ";
        cin >> enteredOTP;
    } while (enteredOTP != otp);

    member_list.push_back(Member(mobile, name, 0.0, pin));
    cout << "Registration is Successful." << endl;
    }
    // Login member
    void loginMember(){
        string mobile, pin;
        cout << "Enter Mobile No. (11-digit): ";
        cin >> mobile;
        cout << "Enter pin: ";
        cin >> pin;
        for (Member& member : member_list)
        {
            if (member.mobileNo == mobile && member.pin == pin)
            {
                current_user = &member;
                cout << "Login is Successful." << endl;
                mainMenu();
                return;
            }
        }
        cout << "Invalid login. Please try again." << endl;
    }

    void sendMoney()
    {
        if (current_user)
        {
            string destMobile;
            cout << "Enter Destination no. (11-digit): ";
            cin >> destMobile;

            Member* recipient = nullptr;
            for (Member& member : member_list)
            {
                if (member.mobileNo == destMobile)
                {
                    recipient = &member;
                    break;
                }
            }
            if (recipient)
            {
                double amount;
                cout << "Enter Amount: ";
                cin >> amount;

                if (current_user->amount >= amount)
                {
                    current_user->amount -= amount;
                    recipient->amount += amount;
                    transactionHistory.push_back(History(transactionHistory.size() + 1, current_user->mobileNo, "Send Money", amount, current_user->amount));
                    transactionHistory.push_back(History(transactionHistory.size() + 1, recipient->mobileNo, "Receive Money", amount, recipient->amount));
                    cout << "Send Money is Successful." << endl;
                }
                else
                {
                    cout << "Insufficient funds." << endl;
                }
            }
            else
            {
                cout << "Destination Mobile no. is invalid." << endl;
            }
        }
        else
        {
            cout << "You need to log in first." << endl;
        }
    }
    void removeMember()
    {
        if (current_user)
        {
            for (auto it = member_list.begin(); it != member_list.end(); ++it)
            {
                if (it->mobileNo == current_user->mobileNo)
                {
                    member_list.erase(it);
                    current_user = nullptr;
                    cout << "Remove is Successful." << endl;
                    return;
                }
            }
        }
        else
        {
            cout << "You need to log in first." << endl;
        }
    }

    void checkBalance() {
        if (current_user) {
            cout << "Balance: " << current_user->amount << endl;
        } else {
            cout << "You need to log in first." << endl;
        }
    }

    void updateMember(Member& member) {
    string newName, oldPIN, newPIN, confirmNewPIN;
    cout << "Old Name: " << member.name << endl;
    cout << "New Name (enter to ignore): ";
    cin.ignore();
    getline(cin, newName);

    cout << "Old PIN: ";
    cin >> oldPIN;

    if (oldPIN != member.pin) {
        cout << "Invalid old PIN." << endl;
        return;
    }

    cout << "New PIN (enter to ignore): ";
    cin >> newPIN;

    if (!newPIN.empty()) {
        cout << "Confirm New PIN: ";
        cin >> confirmNewPIN;

        if (newPIN != confirmNewPIN) {
            cout << "New PINs must be the same." << endl;
            return;
        }
    }

    cout << "Update Me" << endl;
    time_t upTime = time(nullptr);
    string otp = generateOTP();
    cout << "Your OTP is: " << otp << endl;
    cout << "You have 2 minutes to enter the OTP." << endl;
    
    time_t currentTime;
    string enteredOTP;
    do {
        currentTime = time(nullptr);
        if (currentTime - upTime > 120) {
            cout << "OTP time has expired. Registration failed." << endl;
            return;
        }

        cout << "Enter OTP: ";
        cin >> enteredOTP;
    } while (enteredOTP != otp);

    if (!newName.empty()) {
        member.name = newName;
        cout << "Name updated successfully." << endl;
    }

    if (!newPIN.empty()) {
        member.pin = newPIN;
        cout << "PIN updated successfully." << endl;
    }

    cout << "Update is Successful." << endl;
}
    void displayHistory() {
        if (current_user) {
            cout << "Tran ID Description Amount Balance" << endl;
            for (const History& entry : transactionHistory) {
                if (entry.customer_mobile_no == current_user->mobileNo) {
                    cout << " " << entry.Transaction_id_no << " " << entry.Transacyion_type << " " << entry.amount << " " << entry.balance << endl;
                }
            }
        } else {
            cout << "You need to log in first." << endl;
        }
    }

    void mainMenu(){
        int option;
        while (true)
        {
            cout << "** MyCash Menu **" << endl;
            cout << "1. Update Me" << endl;
            cout << "2. Remove Me" << endl;
            cout << "3. Send Money" << endl;
            cout << "4. Cash-In" << endl;
            cout << "5. Cash-Out" << endl;
            cout << "6. Pay Bill" << endl;
            cout << "7. Check Balance" << endl;
            cout << "8. History" << endl;
            cout << "9. Logout" << endl;
            cout << "Enter Your Option (1-9): ";
            cin >> option;

            switch (option)
            {
            case 1:
                updateMember(*current_user);
                break;
            case 2:
                removeMember();
                return;
                break;
            case 3:
                sendMoney();
                break;
            case 4:
                double cashInAmount;
                cout << "Enter Amount: ";
                cin >> cashInAmount;
                current_user->amount += cashInAmount;
                transactionHistory.push_back(History(transactionHistory.size() + 1, current_user->mobileNo, "Cash-In", cashInAmount, current_user->amount));
                cout << "Cash-in is Successful." << endl;
                break;
            case 5:
                double cashOutAmount;
                cout << "Enter Amount: ";
                cin >> cashOutAmount;

                if (current_user->amount >= cashOutAmount)
                {
                    current_user->amount -= cashOutAmount;
                    transactionHistory.push_back(History(transactionHistory.size() + 1, current_user->mobileNo, "Cash-Out", cashOutAmount, current_user->amount));
                    cout << "Cash-out is Successful." << endl;
                }
                else
                {
                    cout << "Insufficient funds." << endl;
                }
                break;
            case 6:
                int billType;
                cout << "Enter Bill Type (Gas/Electricity/Water/Internet-1/2/3/4): ";
                cin >> billType;

                double billAmount;
                switch (billType)
                {
                case 1:
                    billAmount = 1000.0;
                    break;
                case 2:
                    billAmount = 1200.0;
                    break;
                case 3:
                    billAmount = 800.0;
                    break;
                case 4:
                    billAmount = 1000.0;
                    break;
                default:
                    cout << "Invalid Bill Type." << endl;
                    continue;
                }

                cout << "Your " << ((billType == 4) ? "Internet" : "Bill") << " Bill: " << billAmount << endl;
                cout << "Want to pay (Y/N)? ";
                char choice;
                cin >> choice;

                if (choice == 'Y' || choice == 'y')
                {
                    if (current_user->amount >= billAmount)
                    {
                        current_user->amount -= billAmount;
                        transactionHistory.push_back(History(transactionHistory.size() + 1, current_user->mobileNo, "Bill Payment", billAmount, current_user->amount));
                        cout << "Bill Payment is Successful." << endl;
                    }
                    else
                    {
                        cout << "Insufficient funds." << endl;
                    }
                }
                break;
            case 7:
                // Check Balance
                checkBalance();
                break;
            case 8:
                // History
                displayHistory();
                break;
            case 9:
                // Logout
                current_user = nullptr;
                cout << "Logged out." << endl;
                return;
            default:
                cout << "Invalid option. Please try again." << endl;
            }
        }
    }
    void loadMembers() {
    ifstream infile("member_list.txt");
    string mobile, name, pin;
    double amount;
    while (infile >> mobile >> name >> amount >> pin) {
        member_list.push_back(Member(mobile, name, amount, pin));
    }
    infile.close();
}

void saveMembers() {
    ofstream outfile("member_list.txt");
    for (const Member& member : member_list) {
        outfile << member.mobileNo << " " << member.name << " " << fixed << setprecision(2) << member.amount << " " << member.pin << endl;
    }
    outfile.close();
}
};

int main()
{
MyCash myCash;
myCash.loadMembers();

while(true){
    cout<<"***MyCash Login***"<<endl;
    cout<<"1. Login"<<endl;
    cout<<"2. Register"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"   Enter your option:";
    int choice;
    cin>>choice;
    if(choice==1) myCash.loginMember();
    else if(choice==2) myCash.registerMember();
    else if(choice==3) {
            myCash.saveMembers();
        break;
    }
    else cout<<"Invalid Option";
}
}





