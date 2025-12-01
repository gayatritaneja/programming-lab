use std::fs;

fn main()
{
    let data = "hello, writing this to a file hehe";
    fs::write("output.txt", data).expect("Could not write to file!");
}
