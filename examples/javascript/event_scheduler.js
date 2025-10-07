class EventScheduler {
  constructor() {
    this.timeline = [];
  }

  schedule(label, delayMs) {
    const executionTime = Date.now() + delayMs;
    this.timeline.push({ label, executionTime });
    this.timeline.sort((a, b) => a.executionTime - b.executionTime);
  }

  runDueEvents() {
    const now = Date.now();
    const due = this.timeline.filter(event => event.executionTime <= now);
    this.timeline = this.timeline.filter(event => event.executionTime > now);
    due.forEach(event => {
      console.log(`Executing ${event.label} at ${new Date().toISOString()}`);
    });
  }
}

const scheduler = new EventScheduler();
scheduler.schedule("hydrate cache", 100);
scheduler.schedule("refresh metrics", 200);
setTimeout(() => scheduler.runDueEvents(), 250);
