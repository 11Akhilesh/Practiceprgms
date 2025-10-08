class PromisePool {
  constructor(limit) {
    this.limit = limit;
    this.active = 0;
    this.queue = [];
  }

  _run(next) {
    this.active += 1;
    next().finally(() => {
      this.active -= 1;
      if (this.queue.length > 0) {
        const queued = this.queue.shift();
        this._run(queued);
      }
    });
  }

  add(task) {
    if (this.active < this.limit) {
      this._run(task);
    } else {
      this.queue.push(task);
    }
  }
}

const pool = new PromisePool(2);
const delayedTask = label => () =>
  new Promise(resolve => {
    const duration = Math.floor(Math.random() * 200) + 100;
    setTimeout(() => {
      console.log(`${label} finished in ${duration}ms`);
      resolve();
    }, duration);
  });

["A", "B", "C", "D"].forEach(label => pool.add(delayedTask(label)));
