#include <iostream>
using namespace std;
int main()
{
    char temp, letter = 65;
    int n;
    cout << "Please enter a number: ";
    cin >> n;
    /*For the increasing part where letters increase and space decrease*/
    for (int i = 0; i < n; i++)
    {
        temp = letter;
        for (int k = 0; k <= i; k++) // This is for the left side increasing letters.
        {
            cout << temp << " ";
            temp++;
        }
        for (int k = (n - i); k > 1; k--) // This is for the upper space.
        {
            if (k == 2)
            {
                cout << "  ";
                break;
            }
            cout << "    ";
        }
        for (int k = 0; k <= i; k++) // for the right side increasing characters.
        {
            if (k == 0) // This gives temp the highest value possible the first time the loop is done.
                temp = letter + i;
            if (i == (n - 1) && k == 0) // This gets rid of the repitition of the highest value.
                temp -= 1;
            if (i == (n - 1) && k == i) // This removes the unwanted character.
                break;
            cout << temp << " ";
            temp--;
        }
        cout << endl;
    }
    /*The next lines are for the decreasing part where the letters decrease and the nuber of space increase.*/
    for (int i = n; i > 0; i--)
    {
        temp = letter;
        for (int k = 0; k < i; k++) // For lower left letters.
        {
            if (k == (i - 1)) // Removes the last letter of every line.
            {
                break;
            }

            cout << temp << " ";
            temp++;
        }
        for (int k = 0; k <= (n - i); k++) // This is for the lower space.
        {
            if (k == 0)
            {
                cout << "  ";
            }
            else
                cout << "    ";
        }
        for (char k = 1; k < i; k++) // for the right side decreasing characters.
        {
            if (k == 1) // To start with the right letter.
            {
                temp -= 1;
            }

            cout << temp << " ";
            temp--;
        }

        cout << endl;
    }

    return 0;
}
