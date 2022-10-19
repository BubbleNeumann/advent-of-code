#![allow(dead_code)]
// use itertools::Itertools;

fn one_per_line() -> Vec<i32> {
    const FILE_PATH: &str = "./data/day1.input";
    let contents =
        std::fs::read_to_string(FILE_PATH).expect(&format!("can't read {FILE_PATH} file"));

    let mut res = Vec::new();
    for val in contents.trim().split("\n") {
        res.push(val.parse::<i32>().unwrap());
    }

    res
}

fn count_increasing_seq(vec: Vec<i32>, seq_len: usize) -> i32 {
    let mut res: i32 = 0;
    let mut prev_sum = 0;
    let mut cur_sum;

    for i in 0..vec.len() - seq_len {
        cur_sum = 0;
        for j in 0..seq_len {
            cur_sum += vec[i + j];
        }
        res += (cur_sum > prev_sum) as i32;
        prev_sum = cur_sum;
    }

    res
}

fn main() {
    println!("{}", count_increasing_seq(one_per_line(), 1)); // part 1
    println!("{}", count_increasing_seq(one_per_line(), 3)); // part 2
}
