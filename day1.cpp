#include <iostream>
#include <string>
#include <map>
using namespace std;

int getcalib(string line)
{
    int calib = 0;
    bool foundlastdig = false;
    int lastdig = 0;
    string digit = "";
    for (int i = line.size() - 1; i >= 0; i--)
    {
        if (isdigit(line[i]))
        {
            if (!foundlastdig)
            {
                calib += (line[i] - '0');
                foundlastdig = true;
                lastdig = line[i];
            } 
            else
            {
                lastdig = line[i];
            }
        }
    }
    calib += (lastdig - '0') * 10;
    return calib;
}

void replacewords(string &line)
{   
    map<string, int> digits;
    digits["one"] = 1;
    digits["two"] = 2;
    digits["three"] = 3;
    digits["four"] = 4;
    digits["five"] = 5;
    digits["six"] = 6;
    digits["seven"] = 7;
    digits["eight"] = 8;
    digits["nine"] = 9;

    // for (const auto& pair : digits)
    // {
    //     string word = pair.first;
    //     while (line.find(word) != string::npos)
    //     {
    //         int index = line.find(word);
    //         line[index] = digits[word] + '0';
    //         line.erase(index + 1, word.size() - 1);
    //     }
    // }

    string newline;
    
    for (int i = 0; i < line.size(); i++)
    {
        char c = line[i];
        if (isdigit(c))
        {
            newline += c;
        } 
        else if (isalpha(c))
        {
            string digit;
            for (map<string, int>::iterator it = digits.begin(); it != digits.end(); it++)
            {
                digit = it->first;
                string word = line.substr(i, digit.size());
                if (digit == word)
                {
                    // cout << "entered digit == word" << digit << endl;
                    newline += it->second + '0';
                    i += digit.size() - 1;
                    break;
                }
            }
        }
    }

    line = newline;
}

int main()
{
    string line;
    int sum = 0;
    
    // string str = "eightwothree";
    // replacewords(str);
    // cout << str << endl;

    getline(cin, line);
    while (line != "")
    {
        replacewords(line);
        int calib = getcalib(line);
        // cout << calib << endl;
        sum += calib;
        getline(cin, line);
    }

    cout << sum << endl;
}