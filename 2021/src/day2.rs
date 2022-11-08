fn parse(aim_needed: bool) -> i32 {
    const FILE_PATH: &str = "./data/day2.input";
    let contents =
        std::fs::read_to_string(FILE_PATH).expect(&format!("can't read {FILE_PATH} file"));

    let mut forth = 0;
    let mut depth = 0;
    let mut aim = 0;

    for string in contents.trim().split("\n") {
        let mut str_val = "";
        for val in string.trim().split_whitespace() {
            if str_val == "" {
                str_val = val;
                continue;
            }

            let num_val = val.parse::<i32>().unwrap();

            if str_val == "forward" {
                forth += num_val;
                depth += aim * num_val * (aim_needed as i32);
            } else if str_val == "up" {
                depth -= num_val * (!aim_needed as i32);
                aim -= num_val;
            } else {
                depth += num_val * (!aim_needed as i32);
                aim += num_val;
            }

            str_val = "";
        }
    }

    forth * depth
}

fn main() {
    println!("{}", parse(false));
    println!("{}", parse(true));
}
