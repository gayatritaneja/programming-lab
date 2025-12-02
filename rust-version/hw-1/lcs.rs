fn gcd(mut a:i32, mut b:i32) -> i32
{
    while b != 0
    {
        let temp = b;
        b = a % b;
        a = temp;
    }
    a.abs()
}

fn is_comprime_subset(subset: &Vec<i32>) -> bool
{
    let n = subset.len();
    for i in 0..n
    {
        for j in i+1..n
        {
            if gcd(subset[i], subset[j]) != 1
            {
                return false;
            }
        }
    }
    return true;
}

fn sum(subset: &Vec<i32>) -> i32
{
    let mut total = 0;

    for num in subset.iter()
    {
        total += num;
    }
    total
}

fn main()
{
    let arr = vec![2, 3, 4, 5, 7, 9];
    let n = arr.len();

    let mut max_sum = 0;
    let mut best_subset = Vec::new();

    for mask in 0..(1 << n)
    {
        let mut subset = Vec::new();

        for i in 0..n
        {
            if (mask & (1 << i)) != 0
            {
                subset.push(arr[i]);
            }
        }

        if is_comprime_subset(&subset)
        {
            let s = sum(&subset);
            if s > max_sum
            {
                max_sum = s;
                best_subset = subset.clone();
            }
        }
    }
    println!("Max sum: {}", max_sum);
    println!("Best subset = {:?}", best_subset);
}