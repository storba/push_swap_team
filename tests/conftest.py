from __future__ import annotations

from pathlib import Path

import pytest

from .utils_push_swap import PUSH_SWAP_BIN, binary_exists, get_checker_binary


@pytest.fixture(scope="session")
def push_swap_bin() -> Path:
    if not binary_exists(PUSH_SWAP_BIN):
        pytest.skip("push_swap binary not found; build project first")
    return PUSH_SWAP_BIN


@pytest.fixture(scope="session")
def checker_bin() -> Path:
    checker = get_checker_binary()
    if not binary_exists(checker):
        pytest.skip(f"checker binary not found: {checker.name}")
    return checker
