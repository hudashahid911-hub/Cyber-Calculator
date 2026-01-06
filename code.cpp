#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string RESET = "\033[0m";

int main_menu();
void generatePassword();
string randomPasswordGenerator(int length, int upperCase_count, int lowerCase_count, int digits_count, int specialCharacters_count);
unsigned long long int possibleCombinationsCalculator(int length, int upperCase_count, int lowerCase_count, int digits_count, int specialCharacters_count);
unsigned long long int crackingTimeCalculator(unsigned long long int possibleCombinations);
string passwordStrengthCalculator(unsigned long long int timeToCrackInSeconds);
void testPassword();
void testCases();
unsigned long int factorial (int n);
void clearScreen()
{
    system("cls");
}

void heading()
{
    SetConsoleOutputCP(CP_UTF8);
    cout << endl;
    cout << GREEN;
    cout << right << setw(40) << "" << "\t\t  ██████╗ ██╗   ██╗ ██████╗  ███████╗ ██████╗  " << endl;
    cout << right << setw(40) << "" << "\t\t ██╔════╝ ╚██╗ ██╔╝ ██╔══██╗ ██╔════╝ ██╔══██╗ " << endl;
    cout << right << setw(40) << "" << "\t\t ██║       ╚████╔╝  ██████╔╝ █████╗   ██████╔╝ " << endl;
    cout << right << setw(40) << "" << "\t\t ██║        ╚██╔╝   ██╔══██╗ ██╔══╝   ██╔══██╗ " << endl;
    cout << right << setw(40) << "" << "\t\t ╚██████╗    ██║    ██████╔╝ ███████╗ ██║  ██║ " << endl;
    cout << right << setw(40) << "" << "\t\t  ╚═════╝    ╚═╝    ╚═════╝  ╚══════╝ ╚═╝  ╚═╝ " << endl;
    cout << endl;
    cout << right << setw(40) << "" << "  ██████╗  █████╗  ██╗       ██████╗ ██╗   ██╗ ██╗       █████╗  ████████╗  ██████╗  ██████╗  " << endl;
    cout << right << setw(40) << "" << " ██╔════╝ ██╔══██╗ ██║      ██╔════╝ ██║   ██║ ██║      ██╔══██╗ ╚══██╔══╝ ██╔═══██╗ ██╔══██╗ " << endl;
    cout << right << setw(40) << "" << " ██║      ███████║ ██║      ██║      ██║   ██║ ██║      ███████║    ██║    ██║   ██║ ██████╔╝ " << endl;
    cout << right << setw(40) << "" << " ██║      ██╔══██║ ██║      ██║      ██║   ██║ ██║      ██╔══██║    ██║    ██║   ██║ ██╔══██╗ " << endl;
    cout << right << setw(40) << "" << " ╚██████╗ ██║  ██║ ███████╗ ╚██████╗ ╚██████╔╝ ███████╗ ██║  ██║    ██║    ╚██████╔╝ ██║  ██║ " << endl;
    cout << right << setw(40) << "" << "  ╚═════╝ ╚═╝  ╚═╝ ╚══════╝  ╚═════╝  ╚═════╝  ╚══════╝ ╚═╝  ╚═╝    ╚═╝     ╚═════╝  ╚═╝  ╚═╝ " << endl;
    cout << RESET;
    cout << endl;
}

int main()
{
    srand(time(0));
    int choice;
    do
    {
        clearScreen();
        heading();
        cout << right << setw(60) << "1.  " << "Generate Password" << endl;
        cout << endl;
        cout << right << setw(60) << "2.  " << "Test Your Password" << endl;
        cout << endl;
        cout << right << setw(60) << "3.  " << "Test Cases" << endl;
        cout << endl;
        cout << right << setw(60) << "0.  " << "Exit" << endl;
        cout << endl;
        choice = main_menu();
    } while (choice != '0');
    return 0;
}

int main_menu()
{
    char choice;
    cout << right << setw(70) << "" << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case '1':
        generatePassword();
        break;
    case '2':
        testPassword();
        break;
    case '3':
        testCases();
        break;
    case '0':
        cout << RED << right << setw(60) << "" << "Exiting the program...." << RESET << endl;
        break;
    default:
        cout << RED << right << setw(60) << "" << "Invalid choice. Please try again." << RESET << endl;
        cout << "Press ENTER to continue...";
        cin.ignore();
        cin.get();
        break;
    }
    return choice;
}

void generatePassword()
{
    clearScreen();
    heading();
    cout << endl;
    cout << right << setw(70) << "" << "--------------------------" << endl;
    cout << right << setw(70) << "" << "|   GENERATE PASSWORDS   |" << endl;
    cout << right << setw(70) << "" << "--------------------------" << endl;
    int length, specialCharacters_count, digits_count, upperCase_count, lowerCase_count;
    string password = "";

    cout << right << setw(50) << "" << "Enter the desired length of the password: ";
    cin >> length;
    cout << endl;
    cout << right << setw(50) << "" << "Enter the number of UPPERCASE letters you want to add in your password: ";
    cin >> upperCase_count;
    cout << endl;
    cout << right << setw(50) << "" << "Enter the number of LOWERCASE letters you want to add in your password: ";
    cin >> lowerCase_count;
    cout << endl;
    cout << right << setw(50) << "" << "Enter the number of DIGITS you want to add in your password: ";
    cin >> digits_count;
    cout << endl;
    cout << right << setw(50) << "" << "Enter the number of SPECIAL CHARACTERS you want to add in your password: ";
    cin >> specialCharacters_count;
    cout << endl;

    if (upperCase_count + lowerCase_count + digits_count + specialCharacters_count > length)
    {
        cout << RED << right << setw(50) << "" << "The sum of character types is greater than the total length. Please try again." << RESET << endl;
        cout << right << setw(60) << "Press ENTER to continue...";
        cin.ignore();
        cin.get();
        return;
    }
    else if (upperCase_count + lowerCase_count + digits_count + specialCharacters_count < length)
    {
        cout << RED << right << setw(50) << "" << "The sum of character types is less than the total length. Please try again." << RESET << endl;
        cout << right << setw(60) << "Press ENTER to continue...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << right << setw(50) << "";
    for (int i = 0; i < 80; i++)
        cout << "_";
    cout << endl;
    // Generate random password
    password = randomPasswordGenerator(length, upperCase_count, lowerCase_count, digits_count, specialCharacters_count);
    cout << endl;
    cout << right << setw(60) << "" << "Generated Password: " << GREEN << password << RESET << endl;
    cout << endl;

    // Calculate possible combinations
    unsigned long long int possibleCombinations = possibleCombinationsCalculator(length, upperCase_count, lowerCase_count, digits_count, specialCharacters_count);
    cout << right << setw(60) << "" << "Total Possible Combinations: " << GREEN << possibleCombinations << RESET << endl;
    cout << endl;

    // Calculate time to crack the password
    unsigned long long int timeToCrackInSeconds = crackingTimeCalculator(possibleCombinations);
    cout << right << setw(60) << "" << "Estimated Time to Crack Password (in seconds): " << GREEN << timeToCrackInSeconds << RESET << endl;
    cout << endl;
    if (timeToCrackInSeconds > 60)
    {
        cout << right << setw(60) << "" << "Estimated Time to Crack Password (in minutes): " << GREEN << timeToCrackInSeconds / 60 << RESET << endl;
        cout << endl;
    }
    if (timeToCrackInSeconds > 3600)
    {
        cout << right << setw(60) << "" << "Estimated Time to Crack Password (in hours): " << GREEN << timeToCrackInSeconds / 3600 << RESET << endl;
        cout << endl;
    }
    if (timeToCrackInSeconds > 86400)
    {
        cout << right << setw(60) << "" << "Estimated Time to Crack Password (in days): " << GREEN << timeToCrackInSeconds / 86400 << RESET << endl;
        cout << endl;
    }
    // password strength calculation
    string password_strength = passwordStrengthCalculator(timeToCrackInSeconds);
    cout << right << setw(60) << "" << "Password Strength: " << GREEN << password_strength << RESET << endl;
    cout << endl;

    // Suggesting improvements for a better password
    if (password_strength == "weak")
        cout << RED << right << setw(30) << "" << "Consider improving your password strength by increasing its length or adding more character variety." << RESET << endl;
    cout << right << setw(60) << "" << "Press ENTER to continue...";
    cin.ignore();
    cin.get();
}

string randomPasswordGenerator(int length, int upperCase_count, int lowerCase_count, int digits_count, int specialCharacters_count)
{
    string password = "";
    string upperCase_characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowerCase_characters = "abcdefghijklmnopqrstuvwxyz";
    string digits = "0123456789";
    string special_characters = "\\!@#$%^&*()_+-=[]{};':\",.<>/?|~`";
    while (password.length() < length)
    {
        int randType = rand() % 4;
        switch (randType)
        {
        case 0:
            if (upperCase_count > 0)
            {
                password += upperCase_characters[rand() % upperCase_characters.length()];
                upperCase_count--;
            }
            break;
        case 1:
            if (lowerCase_count > 0)
            {
                password += lowerCase_characters[rand() % lowerCase_characters.length()];
                lowerCase_count--;
            }
            break;
        case 2:
            if (digits_count > 0)
            {
                password += digits[rand() % digits.length()];
                digits_count--;
            }
            break;
        case 3:
            if (specialCharacters_count > 0)
            {
                password += special_characters[rand() % special_characters.length()];
                specialCharacters_count--;
            }
            break;
        }
    }
    return password;
}

unsigned long int factorial(int n){
    unsigned long int fact = 1;
    for(int i = 2; i <= n ; i++){
        fact = fact * i;
    }
    return fact;
}

unsigned long long int possibleCombinationsCalculator(int length, int upperCase_count, int lowerCase_count, int digits_count, int specialCharacters_count)
{
    const int noOfUpperCase = 26;
    const int noOfLowerCase = 26;
    const int noOfDigits = 10;
    const int noOfSpecialCharacters = 32;
    unsigned long long int totalCombinations = 1;
    int N = 0; // Character Pool
    if(upperCase_count > 0)
        N += noOfUpperCase;
    if(lowerCase_count > 0)
        N += noOfLowerCase;
    if(digits_count > 0)
        N += noOfDigits;
    if(specialCharacters_count > 0)
        N += noOfSpecialCharacters;
    // Total Combinations
    for(int i = 0; i < length; i++){
        totalCombinations = totalCombinations * N;
    }
    return  totalCombinations;
}

unsigned long long int crackingTimeCalculator(unsigned long long int possibleCombinations)
{
    const int attempts_per_second = 1000000; // 1 million attempts per second

    unsigned long long int timeToCrackInSeconds = possibleCombinations / attempts_per_second;
    return timeToCrackInSeconds;
}

string passwordStrengthCalculator(unsigned long long int timeToCrackInSeconds)
{
    string password_strength;
    if (timeToCrackInSeconds >= 86400)
    {
        password_strength = "very strong";
    }
    else if (timeToCrackInSeconds >= 3600)
    {
        password_strength = "strong";
    }
    else if (timeToCrackInSeconds >= 300)
    {
        password_strength = "moderate";
    }
    else
    {
        password_strength = "weak";
    }
    return password_strength;
}

void testPassword()
{
    clearScreen();
    heading();
    cout << endl;
    cout << right << setw(70) << "" << "----------------------" << endl;
    cout << right << setw(70) << "" << "|   TEST PASSWORDS   |" << endl;
    cout << right << setw(70) << "" << "----------------------" << endl;
    string user_password;
    cout << right << setw(60) << "" << "Enter your password to test its strength: ";
    cin >> user_password;
    int length = user_password.length();
    int upperCase_count = 0, lowerCase_count = 0, digits_count = 0, specialCharacters_count = 0;
    for (int i = 0; i < length; i++)
    {
        if (isupper(user_password[i]))
            upperCase_count++;
        else if (islower(user_password[i]))
            lowerCase_count++;
        else if (isdigit(user_password[i]))
            digits_count++;
        else
            specialCharacters_count++;
    }
    // Calculate possible combinations
    unsigned long long int possibleCombinations = possibleCombinationsCalculator(length, upperCase_count, lowerCase_count, digits_count, specialCharacters_count);
    cout << right << setw(55) << "" << "Total Possible Combinations: " << GREEN << possibleCombinations << RESET << endl;

    // Calculate time to crack the password
    unsigned long long int timeToCrackInSeconds = crackingTimeCalculator(possibleCombinations);
    cout << right << setw(55) << "" << "Estimated Time to Crack Password (in seconds): " << GREEN << timeToCrackInSeconds << RESET << endl;
    if (timeToCrackInSeconds > 60)
        cout << right << setw(55) << "" << "Estimated Time to Crack Password (in minutes): " << GREEN << timeToCrackInSeconds / 60 << RESET << endl;
    if (timeToCrackInSeconds > 3600)
        cout << right << setw(55) << "" << "Estimated Time to Crack Password (in hours): " << GREEN << timeToCrackInSeconds / 3600 << RESET << endl;
    if (timeToCrackInSeconds > 86400)
        cout << right << setw(55) << "" << "Estimated Time to Crack Password (in days): " << GREEN << timeToCrackInSeconds / 86400 << RESET << endl;

    // password strength calculation
    string password_strength = passwordStrengthCalculator(timeToCrackInSeconds);
    cout << right << setw(55) << "" << "Password Strength: " << GREEN << password_strength << RESET << endl;

    // Suggesting improvements for a better password
    if (password_strength == "weak")
        cout << RED << right << setw(30) << "" << "Consider improving your password strength by increasing its length or adding more character variety." << RESET << endl;
    cout << right << setw(60) << "" << "Press any key to continue...";
    cin.ignore();
    cin.get();
}


void testCases()
{
    clearScreen();
    heading();
    cout << endl;
    cout << right << setw(75) << "" << "------------------" << endl;
    cout << right << setw(75) << "" << "|   TEST CASES   |" << endl;
    cout << right << setw(75) << "" << "------------------" << endl;
    cout << endl;
    cout << right << setw(30) << "" << left << setw(30) << "Password" << setw(30) << "Possible Combinations" << setw(30) << "Cracking Time(s)" << setw(30) << "Password Strength" << endl;
    cout << right << setw(30) << "";
    for (int i = 0; i < 110; i++)
        cout << "-";
    cout << endl;
    ifstream fin;
    fin.open("test/testCases.txt");
    if (!fin)
    {
        cout << RED << right << setw(70) << "" << "Error opening testCases.txt file." << RESET << endl;
        return;
    }
    string password;
    while (fin >> password)
    {
        int length = password.length();
        int upperCase_count = 0, lowerCase_count = 0, digits_count = 0, specialCharacters_count = 0;
        for (int i = 0; i < length; i++)
        {
            if (isupper(password[i]))
                upperCase_count++;
            else if (islower(password[i]))
                lowerCase_count++;
            else if (isdigit(password[i]))
                digits_count++;
            else
                specialCharacters_count++;
        }
        // Calculate possible combinations
        unsigned long long int possibleCombinations = possibleCombinationsCalculator(length, upperCase_count, lowerCase_count, digits_count, specialCharacters_count);

        // Calculate time to crack the password
        unsigned long long int timeToCrackInSeconds = crackingTimeCalculator(possibleCombinations);

        // password strength calculation
        string password_strength = passwordStrengthCalculator(timeToCrackInSeconds);

        cout << right << setw(30) << "" << left << setw(30) << password << setw(30) << possibleCombinations << setw(30) << timeToCrackInSeconds << setw(30) << password_strength << endl;
    }
    fin.close();

    cout << endl;
    cout << right << setw(50) << "" << "Press any key to continue...";
    cin.ignore();
    cin.get();
}