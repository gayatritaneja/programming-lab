fn main()
{
    let mut n = 10000;
    let mut max = 0;
    let mut max_i = 0;

    for i in 1..n
    {
        let ans = collatz(i);
        if ans > max
        {
            max = ans;
            max_i = i;
        }
    }
    println!("{}", max);
    println!("{}", max_i);
}


fn collatz(n:i32) -> i32
{
    let mut k = n;
    let mut s = 0;
    while k != 1
    {
        if k % 2 == 0
        {
            k = k/2;
        }
        else
        {
            k = (3 * k) + 1;
        }
        s += 1;
    }
    s
}

fn collatz_rec(mut n:i32, mut s:i32) -> i32
{
    if n == 1
    {
        return s;
    }
    if n % 2 == 0
    {
        collatz_rec(n/2, s+1)
    }
    else
    {
        collatz_rec(3*n+1, s+1)
    }
}