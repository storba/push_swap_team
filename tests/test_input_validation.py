from __future__ import annotations

import pytest

from .utils_push_swap import run_push_swap_raw_args


@pytest.mark.input
@pytest.mark.parametrize(
    "args",
    [
        ["1", "2", "1"],
        ["1", "2", "aa"],
        ["--aa", "1", "2", "11", "9"],
        ["1", "2", "9", "7", "3", "3"],
        ["1", "2", "5", "2147483648", "9", "11"],
        ["1", "2", "5", "-2147483649", "9", "11"],
    ],
)
def test_invalid_input_returns_error(args: list[str], push_swap_bin) -> None:
    result = run_push_swap_raw_args(args)
    assert result.returncode != 0
    assert result.stderr == "Error\n"


@pytest.mark.input
def test_no_arguments_produces_no_output(push_swap_bin) -> None:
    result = run_push_swap_raw_args([])
    assert result.returncode == 1
    assert result.stdout == ""
    assert result.stderr == ""


@pytest.mark.input
def test_already_sorted_input_is_quiet(push_swap_bin) -> None:
    result = run_push_swap_raw_args(["1", "2", "5", "9", "11"])
    assert result.returncode == 0
    assert result.stdout == ""
    assert result.stderr == ""
