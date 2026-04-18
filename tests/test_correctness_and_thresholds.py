from __future__ import annotations

import pytest

from .utils_push_swap import generate_unique_numbers, instruction_count, run_checker, run_push_swap


ALGO_FLAGS = [["--simple"], ["--medium"], ["--complex"], ["--adaptive"]]


@pytest.mark.correctness
@pytest.mark.parametrize("flags", ALGO_FLAGS)
def test_known_case_sorted_by_checker(flags: list[str], push_swap_bin, checker_bin) -> None:
    numbers = [5, 4, 3, 2, 1]
    push_result = run_push_swap(numbers, flags=flags)
    assert push_result.returncode == 0
    assert push_result.stderr == ""

    check_result = run_checker(numbers, push_result.stdout, checker_bin)
    assert check_result.returncode == 0
    assert check_result.stdout.strip() == "OK"


@pytest.mark.correctness
def test_known_case_without_flag_sorted_by_checker(push_swap_bin, checker_bin) -> None:
    numbers = [5, 4, 3, 2, 1]
    push_result = run_push_swap(numbers)
    assert push_result.returncode == 0
    assert push_result.stderr == ""

    check_result = run_checker(numbers, push_result.stdout, checker_bin)
    assert check_result.returncode == 0
    assert check_result.stdout.strip() == "OK"


@pytest.mark.correctness
@pytest.mark.parametrize(
    ("size", "low", "high", "rounds"),
    [
        (5, 0, 100, 10),
        (6, 0, 1000, 10),
        (100, -5000, 5000, 6),
    ],
)
def test_random_cases_sorted_by_checker(
    size: int,
    low: int,
    high: int,
    rounds: int,
    push_swap_bin,
    checker_bin,
) -> None:
    for i in range(rounds):
        numbers = generate_unique_numbers(size, low, high, seed=1000 + i + size)
        push_result = run_push_swap(numbers)
        assert push_result.returncode == 0

        check_result = run_checker(numbers, push_result.stdout, checker_bin)
        assert check_result.returncode == 0
        assert check_result.stdout.strip() == "OK"


@pytest.mark.performance
def test_threshold_size_5_simple(push_swap_bin) -> None:
    for i in range(20):
        numbers = generate_unique_numbers(5, -5000, 5000, seed=2000 + i)
        result = run_push_swap(numbers, flags=["--simple"])
        assert result.returncode == 0
        assert instruction_count(result.stdout) <= 12


@pytest.mark.performance
def test_threshold_size_100_default(push_swap_bin) -> None:
    for i in range(8):
        numbers = generate_unique_numbers(100, -5000, 5000, seed=3000 + i)
        result = run_push_swap(numbers)
        assert result.returncode == 0
        assert instruction_count(result.stdout) <= 700


@pytest.mark.performance
def test_threshold_size_500_default(push_swap_bin) -> None:
    for i in range(4):
        numbers = generate_unique_numbers(500, -2000, 2000, seed=4000 + i)
        result = run_push_swap(numbers)
        assert result.returncode == 0
        assert instruction_count(result.stdout) <= 5500
