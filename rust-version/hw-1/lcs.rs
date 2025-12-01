//generate all possible subsets
    //binary numbers till n-1 give all possible subarrays, 0 means not included and 1 means included
//check if subset is coprime, if it is not, remove
    //every number should be a coprime with every other number
    //run two nested loops -> i and j and check every i's coprimality with every j except when i = j
//add a max variable, if it is a coprime subset and the sum is greater that max, replace the value of max
    //if the subset is coprime, find the sum of the subset
    //if sum is greater than max, rewrite max

//functions we will need
    //isCoprime(a, b)
    //isCoPrimeArray
    //sumArray
    //main: generates all subarrays and performs the main logic

use std::io::{self, Read};
fn main()
{

}

fn gcd(mut a: i64, mut b: i64) -> i64
{
    a = a.abs();
    b = b.abs();
    while b!= 0
    {
        let t = a % b;
        a = b;
        b = t;
    }
    a
}

fn is_coprime(a: i64, b:i64) -> bool
{
    gcd(a, b) == 1
}

fn is_coprime_array(arr: &[i64]) -> bool
{
    let n = arr.len;
    for i in 0..n
    {
        for j in i+1..n
        {
            if !is_coprime(arr[i], arr[j])
            {
                return false;
            }
        }
    }
    true
}

fn sum_array(arr: &[i64]) -> i64
{
    let n = arr.len();
    let mut sum = 0;
    for i in 0..n
    {
        sum = sum + arr[i];
    }
    sum
}

fn main_impl(nums: &[i64]) -> (i64, Vec<i64>)
{
    let n = nums.len();
    
}