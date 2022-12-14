use std::fs;
use std::path::Path;

pub impl collatz {
    fn general(i: u128) {
        let mut path: String = String::from("");
    }
    fn bfs(i: u128) {
    }
}

fn main() {
    let mut num: u128 = 1;
    let mut storage: Vec<String> = Vec::new();
    loop {
        // collatz::general(num);

        num += 1;
        storage.push(num.to_string());

        if num == 10 {
            break;
        }

        if num % 1000 == 0 {
            storage.rev();
            fs::write(Path::new("./stofrage.text"), storage).unwrap();
            storage.rev();
        }
    }
}
