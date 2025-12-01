fn main() {
    let n = 15;
    let count = 5;
    let mut arr = vec![0; n];
    let mut counter = 0;

    arr[0] = 0;
    arr[1] = 0;
    // setting all elements of the sieve to true
    for i in 2..n {
        arr[i] = 1;
    }

    for i in 2..n {
        let mut j = 0;
        while j < n {
            if j != i {
                arr[j] = 0;
            }
            j += i;
        }
    }

    for i in 0..n {
        if arr[i] == 1 {
            counter += 1;
            if count == counter {
                println!("{}th prime number: {}", count, i);
            }
        }
    }
}
