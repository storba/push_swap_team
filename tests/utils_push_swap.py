from __future__ import annotations

import platform
import random
import shutil
import subprocess
from pathlib import Path
from typing import Iterable


REPO_ROOT = Path(__file__).resolve().parent.parent
PUSH_SWAP_BIN = REPO_ROOT / "push_swap"


def binary_exists(path: Path) -> bool:
    return path.exists() and path.is_file()


def get_checker_binary() -> Path:
    system = platform.system()
    if system == "Darwin":
        return REPO_ROOT / "checker"
    return REPO_ROOT / "checker_linux"


def has_valgrind() -> bool:
    return shutil.which("valgrind") is not None


def generate_unique_numbers(
    count: int, low: int, high: int, *, seed: int | None = None
) -> list[int]:
    rng = random.Random(seed)
    population = list(range(low, high + 1))
    return rng.sample(population, count)


def run_command(cmd: list[str], *, input_text: str = "") -> subprocess.CompletedProcess[str]:
    return subprocess.run(
        cmd,
        cwd=REPO_ROOT,
        text=True,
        input=input_text,
        capture_output=True,
        check=False,
    )


def run_push_swap(numbers: Iterable[int], *, flags: list[str] | None = None) -> subprocess.CompletedProcess[str]:
    args = [str(PUSH_SWAP_BIN)]
    if flags:
        args.extend(flags)
    args.extend(str(n) for n in numbers)
    return run_command(args)


def run_push_swap_raw_args(args: list[str]) -> subprocess.CompletedProcess[str]:
    return run_command([str(PUSH_SWAP_BIN), *args])


def run_checker(numbers: Iterable[int], operations: str, checker_bin: Path) -> subprocess.CompletedProcess[str]:
    args = [str(checker_bin), *(str(n) for n in numbers)]
    return run_command(args, input_text=operations)


def instruction_count(operations: str) -> int:
    lines = [line for line in operations.splitlines() if line.strip()]
    return len(lines)
