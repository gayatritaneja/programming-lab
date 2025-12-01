use std::fs;

fn main()
{
    let file = "input.txt";
    let data = fs::read_to_string(file).expect("Could not open file.");
    let mut frequency: Vec<i32> = Vec::new();

    for _ in 0..27
    {
        frequency.push(0);
    }

    for char in data.chars()
    {
        if char.is_ascii_lowercase()
        {
            let index = (char as usize) - ('a' as usize);
            frequency[index] += 1;
        }
        else
        {
            frequency[26] += 1;
        }
    }

    for i in 0..26
    {
        println!("Frequency of {} is {}", (b'a' + i as u8) as char, frequency[i]);
    }
}