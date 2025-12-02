use rand::Rng;

fn main() {
    let mut rng = rand::thread_rng();

    let trials = 10_000;
    let mut total_tosses: u64 = 0;

    for _ in 0..trials {
        let mut history: Vec<char> = Vec::new();
        let mut count = 0;
        let mut pattern_found = false;

        // keep tossing until last 4 tosses are HTHH
        while !pattern_found 
        {
            // toss coin
            let toss = if rng.gen_range(0..=1) == 0 { 'H' } else { 'T' };
            history.push(toss);
            count += 1;

            // check pattern only if we have >= 4 tosses
            if history.len() >= 4 {
                let n = history.len();
                if history[n-4] == 'H' &&
                   history[n-3] == 'T' &&
                   history[n-2] == 'H' &&
                   history[n-1] == 'H'
                {
                    pattern_found = true;
                }
            }
        }

        total_tosses += count;
    }

    let expected = total_tosses as f64 / trials as f64;
    println!("Estimated expected number of tosses: {}", expected);
}
