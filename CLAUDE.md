# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

Competitive programming C++ header-only library. Each algorithm/data structure lives in a single `.hpp` file with `#pragma once` guards. The library is verified against online judges (Library Checker, Yukicoder, AOJ) via [online-judge-verify-helper](https://github.com/online-judge-tools/verification-helper).

## Verification and Testing

Tests are in `test/` mirroring the library directory structure. Each test file (`*.test.cpp`) begins with a `#define PROBLEM "https://..."` directive pointing to an online judge problem URL.

**Run all verifications:**
```bash
pip3 install -U online-judge-verify-helper
oj-verify all
```

**Compile a single test manually:**
```bash
g++ -std=c++17 -I . test/segmenttree/SegmentTree.test.cpp -o a.out
```

The `-I .` flag is required since all includes are relative to the repository root (e.g., `#include "segmenttree/SegmentTree.hpp"`).

**Local debug mode:** Define `MINATO_LOCAL` to enable debug output (`-DMINATO_LOCAL`). Many data structures have `operator<<` overloads gated behind this flag.

## Architecture

### Library Organization

| Directory | Contents |
|---|---|
| `algorithm/` | General algorithms (Mo's algorithm, binary search, LIS, RLE, sqrt decomposition) |
| `atcoder/` | Bundled AtCoder Library (ACL) — excluded from docs generation |
| `datastructure/` | BIT, BinaryTrie, UnionFind variants, RangeSet, SWAG, Compress, TopK |
| `flow/` | Network flow (project selection, max flow with lower bounds) |
| `geometry-integer/` | Integer geometry (Point, CCW, arg_sort) |
| `graph/` | Namori, SCC, edge utilities |
| `math/` | Divisors, totient, floor_sqrt, SquareMatrix, TwoSat, BinomialPrefixSum |
| `mod/` | ModInt, ModComb, FormalPowerSeries, convolution, Berlekamp-Massey, Bostan-Mori |
| `other/` | `template.hpp` (macros, I/O helpers, type aliases), `type_traits.hpp`, BigInt, Rational |
| `segmenttree/` | SegmentTree, LazySegmentTree, DualSegmentTree, DynamicSegmentTree, 2D variants |
| `shortestpath/` | Dijkstra, BFS, Warshall-Floyd |
| `string/` | SuffixArray, RollingHash, Trie, AhoCorasick, Manacher, LCP |
| `tree/` | Rerooting (all-direction DP), HeavyLightDecomposition, Centroid |

### Key Conventions

- **`other/template.hpp`** is included by all test files and provides: type aliases (`ll`, `pii`, `vec<T>`, `vvec<T>`), input macros (`INT(x)`, `LL(x)`, `VEC(type, name, size)`), output (`print(...)`), loop macros (`rep(i, n)`), utility functions (`chmax`, `chmin`, `SZ`, `UNIQUE`, `SUM`), debug printing, and graph I/O helpers.
- Library headers themselves are self-contained and only include standard library headers (or occasionally other library files like `mod/ModInt61.hpp` from `string/RollingHash.hpp`).
- Templates are used extensively — data structures often take function objects as template parameters (e.g., `SegmentTree<T, F>`). Builder functions like `buildPointSetRangeMin()` provide convenient construction.
- Comments are often in Japanese.
