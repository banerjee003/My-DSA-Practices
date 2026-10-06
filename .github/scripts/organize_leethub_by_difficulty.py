#!/usr/bin/env python3

from __future__ import annotations

import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
STATS_PATH = ROOT / "stats.json"
DIFFICULTY_DIRS = {
    "easy": "Difficulty: Easy",
    "medium": "Difficulty: Medium",
    "hard": "Difficulty: Hard",
}


def load_stats() -> dict:
    if not STATS_PATH.exists():
        return {}
    try:
        return json.loads(STATS_PATH.read_text(encoding="utf-8"))
    except json.JSONDecodeError:
        return {}


def move_problem_directories() -> int:
    data = load_stats()
    shas = data.get("leetcode", {}).get("shas", {})
    moved = 0

    for slug, metadata in shas.items():
        if not isinstance(metadata, dict):
            continue

        difficulty = metadata.get("difficulty", "").lower()
        if difficulty not in DIFFICULTY_DIRS:
            continue

        source = ROOT / slug
        if not source.is_dir():
            continue

        destination = ROOT / DIFFICULTY_DIRS[difficulty] / slug
        destination.parent.mkdir(parents=True, exist_ok=True)

        if destination.exists():
            continue

        source.rename(destination)
        print(f"Moved {slug} -> {destination.parent.name}/{slug}")
        moved += 1

    return moved


if __name__ == "__main__":
    moved_count = move_problem_directories()
    print(f"Total moved: {moved_count}")
