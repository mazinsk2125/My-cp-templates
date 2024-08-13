// returns the count of prime numbers in efficient time complexity
int SieveOfEratosthenes(int n)
{
    bool isPrime[n + 1];
    int cnt_of_prime = 0;

    for (int i = 0; i <= n; ++i)
    {
        isPrime[i] = true;
    }

    for (int i = 2; i * i <= n; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        if (isPrime[i])
        {
            ++cnt_of_prime;
        }
    }
    return cnt_of_prime;
}