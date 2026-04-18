from __future__ import annotations

import pytest

from .utils_push_swap import has_valgrind, run_command


pytestmark = pytest.mark.leaks


def _run_valgrind(args: list[str]):
    cmd = [
        "valgrind",
        "--leak-check=full",
        "--error-exitcode=42",
        "./push_swap",
        *args,
    ]
    return run_command(cmd)


def _assert_clean_valgrind_output(result) -> None:
    assert result.returncode == 0
    assert "definitely lost: 0 bytes in 0 blocks" in result.stderr
    assert "ERROR SUMMARY: 0 errors from 0 contexts" in result.stderr


@pytest.fixture(scope="module", autouse=True)
def require_valgrind(push_swap_bin):
    if not has_valgrind():
        pytest.skip("valgrind is not installed")


@pytest.mark.parametrize(
    "args",
    [
        [],
        ["1", "2", "1", "2"],
        ["1", "2", "aaa", "5"],
        ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10"],
    ],
)
def test_valgrind_no_leaks(args: list[str]) -> None:
    result = _run_valgrind(args)
    _assert_clean_valgrind_output(result)


def test_valgrind_no_leaks_random_5() -> None:
    result = _run_valgrind(["4", "19", "2", "8", "13"])
    _assert_clean_valgrind_output(result)
