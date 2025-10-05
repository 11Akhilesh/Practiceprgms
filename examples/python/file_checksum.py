#!/usr/bin/env python3
import hashlib
from pathlib import Path

def sha256_digest(path):
    hasher = hashlib.sha256()
    with path.open("rb") as handle:
        for chunk in iter(lambda: handle.read(8192), b""):
            hasher.update(chunk)
    return hasher.hexdigest()

if __name__ == "__main__":
    working_dir = Path('.')
    targets = sorted(p for p in working_dir.glob('**/*') if p.is_file() and p.suffix)
    for target in targets[:5]:
        print(f"{target}: {sha256_digest(target)}")
