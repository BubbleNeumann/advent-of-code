// https://adventofcode.com/2021/day/3
//
//
// TODO: convert strings to bin

fn read_inp() -> (i32, i32) {
    const FILE_PATH: &str = "./data/day3.input";
    let contents =
        std::fs::read_to_string(FILE_PATH).expect(&format!("can't read {FILE_PATH} file"));

    let mut count_str = 0;
    let mut str_vec: Vec<i32> = Vec::new();
    let mut iter: usize;

    let split_strings = contents.trim().split("\n");

    for string in split_strings.clone() {
        count_str += 1;
        iter = 0;

        for ch in string.to_string().chars() {
            if count_str == 1 {
                str_vec.push((ch == '1') as i32); // get str len
            } else {
                str_vec[iter] += (ch == '1') as i32; // number of ones on iter pos
                iter += 1;
            }
        }
    }

    let mut gamma = 0;
    let mut eps = 0;
    for elem in str_vec.clone() {
        // convert str_vec to dec
        gamma *= 2;
        gamma += (elem >= count_str / 2) as i32;
        eps *= 2;
        eps += (elem < count_str / 2) as i32;
        // print!("{}", (elem >= count_str / 2) as u8);
    }

    // println!();

    let mut prev_max_ox_ind = 0;
    let mut prev_max_co2_ind = 0;
    let mut str_ox = "";
    let mut str_co2 = "";
    for string in split_strings {
        let str_in_bytes = string.as_bytes();
        let mut go_eq: bool;
        for i in 0..string.len() {
            go_eq = (str_in_bytes[0] - 48) == (str_vec[0] >= (count_str / 2)) as u8;
            if go_eq {}
        }
        // let go_eq = str_in_bytes[0] - 48 == (str_vec[0] >= (count_str / 2)) as u8;
        // let mut iter = 1;
        // while iter < string.len()
        //     && ((str_in_bytes[iter] - 48 == (str_vec[iter] >= (count_str / 2)) as u8) == go_eq)
        // {
        //     // println!(
        //     //     "{} {}",
        //     //     str_in_bytes[iter] - 48,
        //     //     (str_vec[iter] >= (count_str / 2)) as u8
        //     // );
        //     if go_eq && iter > prev_max_ox_ind {
        //         prev_max_ox_ind = iter;
        //         str_ox = string;
        //     } else if !go_eq && iter > prev_max_co2_ind {
        //         prev_max_co2_ind = iter;
        //         str_co2 = string;
        //     }
        //
        //     iter += 1;
        // }
        //
        //
    }

    let mut ox = 0;
    let mut co2 = 0;

    str_ox.chars().for_each(|ch| {
        ox = ox * 2 + (ch == '1') as i32;
    });

    str_co2.chars().for_each(|ch| {
        co2 = co2 * 2 + (ch == '1') as i32;
    });

    (gamma * eps, ox * co2)
}

fn main() {
    let gammaeps: i32;
    let ox_co2: i32;
    (gammaeps, ox_co2) = read_inp();
    println!("part 1 {}", gammaeps);
    println!("part 2 {}", ox_co2);
}
