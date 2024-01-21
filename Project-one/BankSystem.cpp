#include <iostream>
#include <string>
using namespace std;

int accounts[100][3]; // 2D array to store account_number, pin_number, and balance
int num_accounts = 0;
int manager_pin_number = 1234;
bool is_open = false;

int main()
{

    cout << "S -- To open the bank.NB: Manager only. " << endl;
    cout << "O -- To open back account. " << endl;
    cout << "B -- To see balance. " << endl;
    cout << "D -- For deposit." << endl;
    cout << "W -- For withdrawl enter capital 'W'." << endl;
    cout << "C -- To close an opened account." << endl;
    cout << "I -- To add interest rate.NB: Manager only." << endl;
    cout << "P -- To see an opened back accounts.NB: Manager only." << endl;
    cout << "E -- To close the bank.NB: Manager only." << endl;
    cout << "\nRemark - In order to access these services you first need to Open the bank";
    cout << endl;
    while (true)
    {
        string transaction_type;
        cout << "Please, Enter the Transaction type you want to perform : ";
        cin >> transaction_type;

        if (transaction_type == "S")
        {
            int manager_pin;
            cout<<" Your are now opening the Bank."<<endl;
            cout << "Manager pin: ";
            cin >> manager_pin;
            if (manager_pin == manager_pin_number)
            {
                is_open = true;
                cout << "Bank is now open." << endl;
            }
            else
            {
                cout << "Incorrect manager pin." << endl;
            }
        }
        else if (transaction_type == "O")
        {
            if (is_open && num_accounts < 100)
            {
                double initial_deposit;
                int pin_number;
                     cout<<" Your are now creating new account."<<endl;
                cout << "Initial deposit: ";
                cin >> initial_deposit;
                cout << "Pin number: ";
                cin >> pin_number;
                if (initial_deposit >= 25)
                {
                    accounts[num_accounts][0] = num_accounts + 1001; // account_number
                    accounts[num_accounts][1] = pin_number;          // pin_number
                    accounts[num_accounts][2] = initial_deposit;     // balance

                    num_accounts++;
                    cout << "Account opened with account number " << num_accounts + 1000 << "." << endl;
                }
                else
                {
                    cout << "Please enter initial deposit greater than 25." << endl;
                }
            }
            else if (!is_open)
            {
                cout << "Bank is not open." << endl;
            }
            else
            {
                cout << "Maximum number of accounts reached." << endl;
            }
        }

        else if (transaction_type == "B")
        {
            if (is_open)
            {
                int account_number, pin_number;
                 cout<<" You are here to see the Balance."<<endl;
                cout << "Account number: ";
                cin >> account_number;
                cout << "Pin number: ";
                cin >> pin_number;

                bool found = false;
                for (int i = 0; i < num_accounts; i++)
                {
                    if (accounts[i][0] == account_number && accounts[i][1] == pin_number)
                    {
                        cout << "Account number: " << accounts[i][0] << ", Balance: " << accounts[i][2] << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Invalid account number or pin number." << endl;
                }
            }
            else
            {
                cout << "Bank is not open." << endl;
            }
        }
        else if (transaction_type == "D")
        {
            if (is_open)
            {
                int account_number, pin_number;
                double amount;
                 cout<<" Deposition into the Bank."<<endl;
                cout << "Account number: ";
                cin >> account_number;
                cout << "Amount: ";
                cin >> amount;
                cout << "Pin number: ";
                cin >> pin_number;

                bool found = false;
                for (int i = 0; i < num_accounts; i++)
                {
                    if (accounts[i][0] == account_number && accounts[i][1] == pin_number)
                    {
                        accounts[i][2] += amount;
                        cout << "Deposit successful. New balance: " << accounts[i][2] << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Invalid account number or pin number." << endl;
                }
            }
            else
            {
                cout << "Bank is not open." << endl;
            }
        }
        else if (transaction_type == "W")
        {
            if (is_open)
            {
                int account_number, pin_number;
                double amount;
                  cout<<" Withdrwal from the Bank."<<endl;
                cout << "Account number: ";
                cin >> account_number;
                cout << "Pin number: ";
                cin >> pin_number;
                cout << "Enter amount:";
                cin >> amount;
                bool found = false;
                for (int i = 0; i < num_accounts; i++)
                {
                    if (accounts[i][0] == account_number && accounts[i][1] == pin_number && is_open && accounts[i][2] >= amount)
                    {
                        accounts[i][2] -= amount;
                        cout << "Withdrawl of " << amount << " succesful. New balance is: " << accounts[i][2] << "." << endl;
                        found = true;
                        break;
                    }
                    else if (accounts[i][0] == account_number && accounts[i][1] == pin_number && is_open)
                    {
                        cout << "Insufficient funds." << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Invalid account number or pin number." << endl;
                }
            }
            else
            {
                cout << "Bank is not open." << endl;
            }
        }
        else if (transaction_type == "C")
        {
            if (is_open)
            {
                int account_number, pin_number;
                  cout<<" Close the opened bank. "<<endl;
                cout << "Account number: ";
                cin >> account_number;
                cout << "Pin number: ";
                cin >> pin_number;

                bool found = false;
                for (int i = 0; i < num_accounts; i++)
                {
                    if (accounts[i][0] == account_number && accounts[i][1] == pin_number && is_open)
                    {
                        is_open = false;
                        cout << "Account closed." << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Invalid account number or pin number." << endl;
                }
            }
            else
            {
                cout << "Bank is not open." << endl;
            }
        }
        else if (transaction_type == "I")
        {
            if (is_open)
            {
                double interest_rate;
                int manager_pin;
                cout << "Interest rate: ";
                cin >> interest_rate;
                cout << "Manager pin: ";
                cin >> manager_pin;
                if (manager_pin == manager_pin_number)
                {
                    for (int i = 0; i < num_accounts; i++)
                    {
                        if (is_open)
                        {
                            double interest = accounts[i][2] * interest_rate / 100;
                            accounts[i][2] += interest;
                        }
                    }
                }
                else
                {
                    cout << "Incorrect manager pin number." << endl;
                }
            }
            else
            {
                cout << "Bank is not open." << endl;
            }
        }
        else if (transaction_type == "P")
        {
            if (is_open)
            {
                char print_type;
                int manager_pin;
                cout << "Enter manager pin number: ";
                cin >> manager_pin;
                if (manager_pin == manager_pin_number)
                {
                    cout << "Enter 'A' to print all accounts and their balances or 'T' to print a specific account and its transactions: ";
                    cin >> print_type;
                    if (print_type == 'A')
                    {
                        for (int i = 0; i < num_accounts; i++)
                        {
                            cout << "Account number: " << accounts[i][0] << ", Balance: " << accounts[i][2] << endl;
                        }
                    }
                    else if (print_type == 'T')
                    {
                        int account_number;
                        cout << "Enter the account number: ";
                        cin >> account_number;
                        bool found = false;
                        for (int i = 0; i < num_accounts; i++)
                        {
                            if (accounts[i][0] == account_number)
                            {
                                found = true;
                                cout << "Account number: " << accounts[i][0] << endl;
                                for (int j = 3; j <= accounts[i][2] + 2; j++)
                                {
                                    cout << "Transaction " << j - 2 << ": " << accounts[i][j] << endl;
                                }
                                break;
                            }
                        }
                        if (!found)
                        {
                            cout << "Invalid account number." << endl;
                        }
                    }
                    else
                    {
                        cout << "Invalid print type." << endl;
                    }
                }
                else
                {
                    cout << "Incorrect pin number." << endl;
                }
            }
            else
            {
                cout << "Bank is not open." << endl;
            }
        }
        else if (transaction_type == "E")
        {
            if (is_open)
            {
                int manager_pin;
                cout << "Enter manager pin number: ";
                cin >> manager_pin;
                if (manager_pin == manager_pin_number && is_open)
                {
                    is_open = false;
                    cout << "All accounts have been closed. Exiting program..." << endl;
                    exit(0);
                }
                else
                {
                    cout << "Invalid manager pin number." << endl;
                }
            }
            else
            {
                cout << "Bank is not open." << endl;
            }
        }
    }
}
