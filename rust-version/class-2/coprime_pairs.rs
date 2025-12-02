use std::io;

fn main()
{
    let n = 15;

    for i in 2..n+1
    {
        if (is_prime(i))
        {
            if is_prime(i+2)
            {
                println!("Coprimes pair: {} {}", i, i+2);
            }
        }
    }
}

fn is_prime(n: u64) -> bool {
    if n < 2 {
        return false;
    }
    if n == 2 || n == 3 {
        return true;
    }
    if n % 2 == 0 {
        return false;
    }

    let mut i = 3;
    while i * i <= n {
        if n % i == 0 {
            return false;
        }
        i += 2;
    }

    true
}
