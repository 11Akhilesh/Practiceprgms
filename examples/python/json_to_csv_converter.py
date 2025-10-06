#!/usr/bin/env python3
import csv
import json
from pathlib import Path

def json_to_csv(source_path, target_path):
    data = json.loads(source_path.read_text(encoding='utf-8'))
    if not isinstance(data, list):
        raise ValueError('Expecting a list of dictionaries')
    fieldnames = sorted({key for item in data for key in item})
    with target_path.open('w', newline='', encoding='utf-8') as handle:
        writer = csv.DictWriter(handle, fieldnames=fieldnames)
        writer.writeheader()
        for row in data:
            writer.writerow(row)

if __name__ == "__main__":
    fixture = [
        {"task": "ingest", "duration": 3.2, "status": "ok"},
        {"task": "transform", "duration": 5.1, "status": "ok"},
        {"task": "publish", "duration": 4.8, "status": "warning"},
    ]
    source = Path('sample.json')
    source.write_text(json.dumps(fixture), encoding='utf-8')
    json_to_csv(source, Path('sample.csv'))
    print('Generated sample.csv from sample.json')
