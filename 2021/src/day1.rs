#![allow(dead_code)]
// use itertools::Itertools;


fn part1() {
    const FILE_PATH: &str = "./data/day1.input";
    let contents = std::fs::read_to_string(FILE_PATH)
        .expect(&format!("can't read {FILE_PATH} file"));

    let mut prev = -1;
    let mut result = -1;

    for val in contents.trim().split("\n") {
        let depth = val.parse::<i32>().unwrap();
        result += (depth > prev) as i32;
        prev = depth;
    }

    println!("{result}");
}

fn main() { }
