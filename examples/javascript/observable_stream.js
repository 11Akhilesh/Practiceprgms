class Observable {
  constructor(subscribe) {
    this._subscribe = subscribe;
  }

  subscribe(observer) {
    return this._subscribe(observer);
  }

  map(transform) {
    return new Observable(observer =>
      this.subscribe({
        next: value => observer.next(transform(value)),
        complete: () => observer.complete()
      })
    );
  }
}

const interval = delay =>
  new Observable(observer => {
    let count = 0;
    const id = setInterval(() => {
      observer.next(count++);
      if (count > 5) {
        clearInterval(id);
        observer.complete();
      }
    }, delay);
    return () => clearInterval(id);
  });

const subscription = interval(100)
  .map(value => value * 2)
  .subscribe({
    next: value => console.log("Value:", value),
    complete: () => console.log("Done")
  });

setTimeout(() => subscription(), 800);
