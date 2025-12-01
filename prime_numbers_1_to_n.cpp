/* Algorithm Challenge & Problem Solving
 * 2 Enum representing whether a number is prime or not.
 */

#include <iostream>
#include <cmath>
using namespace std;

enum enPrimNotPrime
{
    Prim = 1,
    NotPrime = 2
};

/*
 * Reads a positive number from the user.
 * Keeps asking until the user enters a value greater than 0.
 */
int ReadPositiveNumber(string Massage)
{
    int Number = 0;
    do
    {
        cout << Massage;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

/*
 * Checks whether a given number is prime.
 * A number is NOT prime if it can be divided by any integer from 2 to Number/2.
 * If no divisor is found → the number is prime.
 */
enPrimNotPrime CheckPrime(int Number)
{
    int M = round(Number / 2);

    for (int Counter = 2; Counter <= M; Counter++)
    {
        // If the number is divisible by any counter → it's not prime
        if (Number % Counter == 0)
            return enPrimNotPrime::NotPrime;
    }

    // If no divisors were found → it's prime
    return enPrimNotPrime::Prim;
}

/*
 * Prints all prime numbers from 1 to N.
 * Calls CheckPrime() for every number in the range.
 */
void PrintPrimeNumbersFrom1toN(int Number)
{
    cout << "\n";
    cout << "Prime Number From " << 1 << " To " << Number << " are : " << endl;

    for (int i = 1; i <= Number; i++)
    {
        // Print only the numbers that are prime
        if (CheckPrime(i) == enPrimNotPrime::Prim)
        {
            cout << i << endl;
        }
    }
}

int main()
{
    // Reads a positive number and prints all primes from 1 up to that number
    PrintPrimeNumbersFrom1toN(ReadPositiveNumber("Please Enter a Positive Number"));

    return 0;
}
