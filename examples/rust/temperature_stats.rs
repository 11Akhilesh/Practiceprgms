use std::collections::VecDeque;

struct RollingAverage {
    window: VecDeque<f64>,
    limit: usize,
    sum: f64,
}

impl RollingAverage {
    fn new(limit: usize) -> Self {
        Self {
            window: VecDeque::with_capacity(limit),
            limit,
            sum: 0.0,
        }
    }

    fn push(&mut self, value: f64) {
        if self.window.len() == self.limit {
            if let Some(old) = self.window.pop_front() {
                self.sum -= old;
            }
        }
        self.window.push_back(value);
        self.sum += value;
    }

    fn average(&self) -> f64 {
        if self.window.is_empty() {
            0.0
        } else {
            self.sum / self.window.len() as f64
        }
    }
}

fn main() {
    let mut stats = RollingAverage::new(4);
    let samples = [21.0, 22.5, 23.1, 24.0, 23.4, 22.8];
    for value in samples {
        stats.push(value);
        println!("Updated average: {:.2}", stats.average());
    }
}
