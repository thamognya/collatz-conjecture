impl collatz {
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
        collatz::general(num);
        num += 1;
        println!("{}", num);
        if num == 10 {
            break;
        }
    }
}
