/**
 * bool isPrime(int n)
 * Description: To check a number that is a prime or not
 */
bool isPrime(int n)
{
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return false;
    return true;
}