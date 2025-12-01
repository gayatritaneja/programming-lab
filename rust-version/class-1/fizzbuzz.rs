fn main()
{
    let n = 100;
    for i in 1..n+1
    {
        let three = "fizz";
        let five = "buzz";
        let mut flag = true;

        if i % 3 == 0
        {
            print!("{}", three);
            flag = false;
        }
        if i % 5 == 0
        {
            print!("{}", five);
            flag = false;
        }


        if flag == true
        {
            print!("{}", i);
        }
        println!();
        flag = true;
    }
}