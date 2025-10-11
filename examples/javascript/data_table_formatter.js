function formatTable(rows) {
  const headers = Object.keys(rows[0]);
  const widths = headers.map(header =>
    Math.max(header.length, ...rows.map(row => String(row[header]).length))
  );
  const divider = "+" + widths.map(width => "-".repeat(width + 2)).join("+") + "+";

  const renderRow = row =>
    "| " +
    headers
      .map((header, index) => String(row[header]).padEnd(widths[index], " "))
      .join(" | ") +
    " |";

  console.log(divider);
  console.log(
    renderRow(
      headers.reduce((acc, header) => ({ ...acc, [header]: header.toUpperCase() }), {})
    )
  );
  console.log(divider);
  rows.forEach(row => console.log(renderRow(row)));
  console.log(divider);
}

formatTable([
  { region: "us-east", latency: 21, status: "ok" },
  { region: "eu-west", latency: 35, status: "degraded" },
  { region: "ap-south", latency: 29, status: "ok" }
]);
