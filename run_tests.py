#!/usr/bin/env python3
from __future__ import annotations

import argparse
import subprocess
import sys


def build_pytest_command(marker: str | None, extra_args: list[str]) -> list[str]:
    cmd = [sys.executable, "-m", "pytest"]
    if marker:
        cmd.extend(["-m", marker])
    cmd.extend(extra_args)
    return cmd


def main() -> int:
    parser = argparse.ArgumentParser(description="Run push_swap pytest suite")
    parser.add_argument(
        "--suite",
        choices=["all", "input", "correctness", "performance", "leaks"],
        default="all",
        help="select a pytest marker subset",
    )
    parser.add_argument(
        "pytest_args",
        nargs=argparse.REMAINDER,
        help="additional args passed to pytest (prefix with --)",
    )
    args = parser.parse_args()

    marker = None if args.suite == "all" else args.suite
    cmd = build_pytest_command(marker, args.pytest_args)
    return subprocess.call(cmd)


if __name__ == "__main__":
    raise SystemExit(main())
