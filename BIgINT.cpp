
#include <bits/stdc++.h>
using namespace std;

// Defining new data type
class bigINT
{
    // Store the number as a string
    // internally
    string number;

public:
    // Constructor to initialize the
    // number at the time of creation
    bigINT(string number)
    {
        this->number = number;
    }

    // Method to get the number of
    // digits in the big integer
    int numDigits()
    {
        return this->number.length();
    }

    // operator overloading for comparison
    // whether two big integers are equal
    // or not
    bool operator==(bigINT other)
    {
        if (this->number.length() !=
            other.number.length())
            return false;
        for (int i = 0;
             i < this->number.length();
             i++)
        {
            if (this->number[i] !=
                other.number[i])
                return false;
        }
        return true;
    }

    // Operator overloading for comparison
    // whether first big integers is less
    // than second big integer or not
    bool operator<(bigINT other)
    {
        if (this->number.length() <
            other.number.length())
            return true;
        if (this->number.length() >
            other.number.length())
            return false;
        return (this->number[0] <
                other.number[0]);
    }

    // Operator overloading for comparison
    // whether first big integers is greater
    // than second big integer or not
    bool operator>(bigINT other)
    {
        if (this->number.length() >
            other.number.length())
            return true;
        if (this->number.length() <
            other.number.length())
            return false;
        return (this->number[0] >
                other.number[0]);
    }

    // Operator overloading for comparison
    // whether first big integers is less
    // than or equal to second big integer
    // or not
    bool operator<=(bigINT other)
    {
        if (this->number.length() <
            other.number.length())
            return true;
        if (this->number.length() >
            other.number.length())
            return false;
        for (int i = 0;
             i < this->number.length();
             i++)
        {
            if (this->number[0] >
                other.number[0])
                return false;
        }
        return true;
    }

    // Operator overloading for comparison
    // whether first big integers is greater
    // than or equal to second big integer
    // or not
    bool operator>=(bigINT other)
    {
        if (this->number.length() >
            other.number.length())
            return true;
        if (this->number.length() <
            other.number.length())
            return false;
        for (int i = 0;
             i < this->number.length();
             i++)
        {
            if (this->number[0] <
                other.number[0])
                return false;
        }
        return true;
    }

    // Operator overloading for addition
    // of two big integers
    bigINT operator+(bigINT other)
    {
        if (this->number.length() <=
            other.number.length())
        {
            reverse(this->number.begin(),
                    this->number.end());
            reverse(other.number.begin(),
                    other.number.end());
            int extraZeroes = other.number.length() -
                              this->number.length();
            for (int i = 0;
                 i < extraZeroes; i++)
            {
                this->number.push_back('0');
            }
        }
        if (this->number.length() >
            other.number.length())
        {
            reverse(this->number.begin(),
                    this->number.end());
            reverse(other.number.begin(),
                    other.number.end());
            int extraZeroes = this->number.length() -
                              other.number.length();
            for (int i = 0;
                 i < extraZeroes;
                 i++)
            {
                other.number.push_back('0');
            }
        }
        string answer = "";
        int carry = 0;
        int ansDigit = 0;
        for (int i = 0;
             i < this->number.length();
             i++)
        {
            int firstDigit = this->number[i] - '0';
            int secondDigit = other.number[i] - '0';
            int sum = firstDigit + secondDigit + carry;
            ansDigit = sum % 10;
            carry = sum / 10;
            char toPush = ansDigit + '0';
            answer += toPush;
            if (i == this->number.length() - 1 &&
                carry != 0)
            {
                char extraPush = carry + '0';
                answer += extraPush;
            }
        }
        reverse(answer.begin(),
                answer.end());
        return answer;
    }

    // Operator overloading for
    // multiplication of two integers
    bigINT operator*(bigINT other)
    {
        vector<bigINT> result;
        reverse(other.number.begin(),
                other.number.end());
        for (int i = 0;
             i < this->number.length();
             i++)
        {
            int carry = 0;
            int product = 0;
            string ans = "";
            int digit = this->number[i] - '0';
            for (int j = 0;
                 j < other.number.length();
                 j++)
            {
                int otherDigit = other.number[j] - '0';
                product = digit * otherDigit + carry;
                carry = product / 10;
                int remainderNumber = carry * 10;
                int number;
                if (remainderNumber != 0)
                    number = product % remainderNumber;
                else
                    number = product % 10;
                char toPush = number + '0';
                ans += toPush;
                if (j == other.number.length() - 1 &&
                    carry != 0)
                {
                    char extraPush = carry + '0';
                    ans += extraPush;
                }
            }
            for (int k = 0;
                 k < this->number.length() - i - 1;
                 k++)
            {
                ans = '0' + ans;
            }
            reverse(ans.begin(), ans.end());
            bigINT add(ans);
            result.push_back(add);
        }
        bigINT sum("0");
        for (int i = 0;
             i < result.size();
             i++)
        {
            sum = sum + result[i];
        }
        return sum;
    }

    // Operator overloading for printing
    // the big integer on the console output
    friend ostream &operator<<(ostream &out,
                               const bigINT &bin)
    {
        out << bin.number;
        out << endl;
        return out;
    }

    // Operator overloading which gives a
    // big integer which is a big integer
    // raised to some unsigned integer
    bigINT operator^(unsigned int n)
    {
        bigINT result("1");
        bigINT repeat(this->number);
        for (int i = 0; i < n; i++)
        {
            result = result * repeat;
        }
        return result;
    }

    // Postfix increment
    void operator++(int)
    {
        bigINT newNumber(this->number);
        newNumber = newNumber + bigINT("1");
        this->number = newNumber.number;
    }

    // Prefix increment
    void operator++()
    {
        bigINT newNumber(this->number);
        newNumber = newNumber + bigINT("1");
        this->number = newNumber.number;
    }
};

// Non member function that return
// the n-th fibonacci number
bigINT fibonacci(unsigned int n)
{
    bigINT first("0");
    bigINT second("1");
    if (n == 0)
        return first;
    if (n == 1)
        return second;
    bigINT fib("0");
    for (int i = 2; i <= n; i++)
    {
        fib = first + second;
        first = second;
        second = fib;
    }
    return fib;
}

// Non member function that converts
// a simple integer to bigINT
bigINT integerTobigINT(unsigned int n)
{
    string result = "";
    while (n > 0)
    {
        int digit = n % 10;
        n /= 10;
        char toPush = digit + '0';
        result += toPush;
    }
    reverse(result.begin(),
            result.end());
    bigINT temp(result);
    return temp;
}

// Non member function that return
// the factorial of a given number n
bigINT factorial(unsigned int n)
{
    bigINT fact("1");
    if (n <= 1)
        return fact;
    for (int i = 2; i <= n; i++)
    {
        fact = fact * integerTobigINT(i);
    }
    return fact;
}

// Driver code
int main()
{
    // Defining an initialising a
    // big integer
    bigINT first("12345");
    cout << "The number of digits in first big integer = " << first.numDigits() << endl;
    bigINT second("12345");
    if (first == second)
    {
        cout << "first and second are equal!\n";
    }
    else
        cout << "Not equal!\n";
    bigINT third("10000");
    bigINT fourth("100000");
    if (third < fourth)
    {
        cout << "third is smaller than fourth!\n";
    }
    bigINT fifth("10000000");
    if (fifth > fourth)
    {
        cout << "fifth is larger than fourth!\n";
    }

    // Printing all the numbers
    cout << "first = " << first;
    cout << "second = " << second;
    cout << "third = " << third;
    cout << "fourth = " << fourth;
    cout << "fifth = " << fifth;

    // Incrementing the value of first
    first++;
    cout << "After incrementing the value of first is : ";
    cout << first;
    bigINT sum = fourth + fifth;
    cout << "Sum of fourth and fifth = " << sum;
    bigINT product = second * third;
    cout << "Product of second and third = " << product;

    // Print the fibonaccii number from 1 to 100
    cout << "-------------------------fibonacci------------------------------\n";
    for (int i = 0; i <= 100; i++)
    {
        bigINT fib = fibonacci(i);
        cout << "fibonacci " << i << " = " << fib;
    }

    // Calculating factorial of from 1 to 100
    cout << "-------------------------factorial------------------------------\n";
    for (int i = 0; i <= 100; i++)
    {
        bigINT fact = factorial(i);
        cout << "factorial of " << i << " = ";
        cout << fact;
    }
}