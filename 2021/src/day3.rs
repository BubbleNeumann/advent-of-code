// https://adventofcode.com/2021/day/3
//
// TODO: convert strings to bin

use std::{f32::NAN, ptr::null, u32};

use itertools::{join, Itertools};

fn part1() -> u32 {
    const FILE_PATH: &str = "./data/day3.input";
    let contents =
        std::fs::read_to_string(FILE_PATH).expect(&format!("can't read {FILE_PATH} file"));

    let mut cnt_lines = 0;  // overall num of lines

    let mut split_strings = contents.trim().split("\n");
    let str_len = split_strings.nth(0).unwrap().len();
    let mut cnt_zeros = vec![0; str_len];

    for str in split_strings {
        cnt_lines += 1;
        for (i, literal) in str.chars().enumerate() {
            cnt_zeros[i] += (literal == '0') as u32;
        }
    }

    let mut gamma: u32 = 0;

    for cnt_digit in cnt_zeros.iter() {
        gamma = (gamma << 1) + (*cnt_digit < cnt_lines-cnt_digit) as u32;  // cnt_zeros < cnt_ones
    }

    let eps = gamma^u32::MAX>>(32-str_len);  // bitwise opposite excluding leading zeros
    println!("gamma={:b}, eps={:b}", gamma, gamma^u32::MAX>>gamma.leading_zeros());

    gamma*eps
}

fn part2() -> u32 {
    const FILE_PATH: &str = "./data/day3.input";
    let contents =
        std::fs::read_to_string(FILE_PATH).expect(&format!("can't read {FILE_PATH} file"));

    let mut cnt_lines = 0;  // overall num of lines

    let mut split_strings = contents.trim().split("\n");
    let str_len = split_strings.nth(0).unwrap().len();
    let mut cnt_zeros = vec![0; str_len];

    for str in split_strings.clone() {
        cnt_lines += 1;
        for (i, literal) in str.chars().enumerate() {
            cnt_zeros[i] += (literal == '0') as u32;
        }
    }

    let mut gamma: u32 = 0; // now its oxygen

    for cnt_digit in cnt_zeros.iter() {
        gamma = (gamma << 1) + (*cnt_digit < cnt_lines-cnt_digit) as u32;  // cnt_zeros < cnt_ones
    }

    // let eps = gamma^u32::MAX>>(32-str_len);  // and now its CO2
    // let eps = gamma^u32::MAX>>(32-str_len);  // bitwise opposite excluding leading zeros


    // need to find the most similar BUTTT! not exactly

    // TODO apply leading zeros
    let mut gamma_str: String = format!("{:b}", gamma);
    let len = str_len-gamma_str.clone().len();
    println!("gammmmaaa={gamma_str}, {len}");
    let leading_zeros: String = "0".repeat(str_len-gamma_str.clone().len());

    gamma_str = leading_zeros + &gamma_str;
    println!("gammmmaaa={gamma_str}, {len}");
    // let max_substr_len = gamma_str.clone().len();

    // let eps = gamma^u32::MAX>>gamma.leading_zeros();  // and now its CO2
    // println!("gamma={:b}, eps={:b}", gamma, eps);

    let mut substr_len = 3;
    let mut oxygen: u32 = 0;
    let mut count;

    while substr_len <= str_len {
        count = 0;

        for string in split_strings.clone() {
            if count > 2 {
                break;
            }
            if string.starts_with(&gamma_str[0..substr_len]) {
                count += 1;
                // oxygen = gamma_str.parse().unwrap();
                oxygen = u32::from_str_radix(string, 2).unwrap();
            }
        }
        if count == 1 {
            println!("yaay");
            break;  // required value already set
        } else if  count == 2 {  // need to choose one out of 2
            println!("yaay 2");
            for string in split_strings.clone() {
                if string.starts_with(&gamma_str[0..substr_len]) && string.chars().nth(substr_len).unwrap() == '1' {
                    // oxygen = string.parse().unwrap();
                    oxygen = u32::from_str_radix(string, 2).unwrap();
                }
            }
            break;
        } else {
            substr_len += 1;
        }
    }

    let mut co2: u32 = 0;

    // TODO apply leading zeros
    // let mut eps_str: String = format!("{:b}", eps);
    let mut eps_str = gamma_str.chars().map(|c| if c == '0' { '1' } else { '0' }).collect::<String>();

    let len = str_len-eps_str.clone().len();
    println!("epssssssssssss={eps_str}, {len}");
    let leading_zeros: String = "0".repeat(len);
    eps_str = leading_zeros.clone() + &eps_str;
    println!("{eps_str}");

    substr_len = len;

    while substr_len <= str_len {
        count = 0;

        for string in split_strings.clone() {
            if count > 2 {
                break;
            }
            if string.starts_with(&eps_str[0..substr_len]) {
                count += 1;
                // co2 = eps_str.parse().unwrap();
                co2 = u32::from_str_radix(string, 2).unwrap();
            }
        }
        if count == 1 {
            println!("yaay");
            break;  // required value already set
        } else if count == 2 {  // need to choose one out of 2
            for string in split_strings.clone() {
                if string.starts_with(&eps_str[0..substr_len]) && string.chars().nth(substr_len).unwrap() == '0' {
                    // co2 = string.parse().unwrap();
                    println!("yaay 2");
                    co2 = u32::from_str_radix(string, 2).unwrap();
                    println!("{string}");
                }
            }
            break;
        } else {
            substr_len += 1;
        }
    }
    println!("{}", oxygen);
    println!("{}", co2);

    
    oxygen*co2
}

fn main() {
    println!("part 1 = {}", part1());
    println!("part 2 = {}", part2());
}
