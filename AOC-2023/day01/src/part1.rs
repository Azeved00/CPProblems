fn char_to_int(c:char) -> i32 {
    let s = c.to_string();
    return s.parse().unwrap();
}

fn main() {
    let mut sum:i32 = 0;
    let input = "1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet".to_string();


    let lines = input.split("\n");
    for line in lines{
        let mut first = 0;  
        let mut last  = 0;
        for c in line.chars() {
            if !c.is_numeric() {
                continue;
            }
            let temp = char_to_int(c);
            
            if first == 0 {
                first = temp * 10;
            }
            
            last = temp;

        }
        sum += first + last;
    }

    println!("sum: {}", sum);
}
