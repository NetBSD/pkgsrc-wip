# AGENTS.md

This is the **NetBSD pkgsrc WIP packaging** for llama.cpp (`wip/llama.cpp`), not the upstream
source tree. The upstream llama.cpp source lives inside `work/` and is untracked
build state: **never edit it, and never commit or reference it**. Edits made to
files in `work/` are wiped on the next `make clean` / extract. All actual
package source lives in the pkgsrc metadata files at the top level:
`Makefile`, `Makefile.common`, `distinfo`, `PLIST`, `DESCR`, `TODO`, `patches/`.

Upstream is https://github.com/ggml-org/llama.cpp (the project moved from
`ggerganov/` to `ggml-org/`; only `HOMEPAGE` in `Makefile` still cites the old
org). See `work/llama.cpp-b10276/AGENTS.md` for upstream contribution rules,
which apply only if you are contributing upstream, not for packaging work.

## What this package is

A pkgsrc WIP (work-in-progress) package. Key facts:

- **Version scheme is unusual**: upstream publishes "builds" tagged `b10276`,
  but the pkgsrc `PKGNAME` must be a dotted version, so `Makefile` does
  `PKGNAME= ${DISTNAME:S/-b/-${LLAMA_CPP_VAR}./}` with
  `LLAMA_CPP_VAR= 0.0.2` (the comment explains: "because 'b' is the second
  letter of the alphabet"). Result: `llama.cpp-0.0.2.10276`.
- `Makefile.common` is **shared**: it is included by `wip/llama.cpp/Makefile`
  and `wip/py-llama-cpp-scripts/Makefile`. Do not move variables out of it into
  `Makefile` without checking the other consumer.
- `LLAMA_BUILD_NUMBER` and `LLAMA_BUILD_COMMIT` (in `Makefile.common`) must match
  the exact upstream release being packaged; they are compiled into the binary
  (`-DLLAMA_BUILD_NUMBER/COMMIT` cmake args). Bumping the release means bumping
  these three things together: `GITHUB_TAG`/`LLAMA_BUILD_NUMBER`,
  `LLAMA_BUILD_COMMIT`, and `distinfo` checksums.
- **Two distfiles**: the source tarball plus a separate web UI tarball
  `llama-${GITHUB_TAG}-ui.tar.gz` fetched from the GitHub release page
  (`SITES.llama-...=` line in `Makefile`). Both must be added to `distinfo`
  (BLAKE2s, SHA512, Size).
- `post-extract` symlinks `${WRKDIR}/llama-${GITHUB_TAG}` into
  `${WRKSRC}/tools/ui/dist`, so the web UI must be extracted in `WRKDIR` (it
  can't be a plain DISTFILES target with its own subdir without adjusting this).
- Build uses **cmake** (not make). **Bundled ggml is used** (`LLAMA_USE_SYSTEM_GGML`
  is NOT set): ggml 0.18.1 is built from the tarball's `ggml/` subdir so llama
  b10276 gets the exact API it expects. This means the package *ships its own*
  `libggml*.so` (see PLIST) and depends on **OpenBLAS** (`math/blas`), not on
  `math/ggml`. History: a `-DLLAMA_USE_SYSTEM_GGML=YES` era (against pkgsrc
  `math/ggml-0.15.3`) was reverted because llama b10276's bundled ggml is 0.18.1
  and the old system ggml lacks `GGML_TYPE_Q2_0`, `ggml_lightning_indexer`,
  `ggml_dsv4_hc_*`, which llama calls unconditionally (DeepSeek-32/4, GLM-DSA,
  Q1_0/Q2_0 quant types). Keep the two in sync: if you bump to a llama build
  whose bundled ggml is >0.18.x, no separate ggml package bump is needed since
  it's bundled.
- Shared libraries are versioned with the build number:
  `lib/libllama.so.0.0.${LLAMA_BUILD_NUMBER}` etc. `Makefile` uses
  `PRINT_PLIST_AWK` + `PLIST_SUBST` to keep `PLIST` stable across bumps, so
  the literal `PLIST` line still says `${LLAMA_BUILD_NUMBER}`; do not hand-edit
  it to a real number. **Exception**: the bundled ggml libs keep their *own*
  ggml version (e.g. `0.18.1`), hardcoded in PLIST, not the llama build number.
- Installs **many** binaries (about 40 `bin/llama-*` tools, plus bundled ggml
  headers/libs, see `PLIST`).

## Commands

Run from `/bd/pkgsrc/wip/llama.cpp` (the package dir). `work/` is gitignored
(via `wip/.gitignore`), so changes inside it never show in `git status`.

- `bmake` — build. The work directory already has completed `configure`,
  `build`, `depends` phases (`.configure_done`, `.buildlink_*` markers), so
  incremental rebuilds are fast. Must be run from a shell where `bmake` and the
  NetBSD tools are available.
- `bmake clean` / `bmake clean CONFIGURED=yes` — clean; also wipes `work/`
  (the extracted upstream source).
- `bmake package` / `bmake stage-install` — package staging.
- `bmake install` / `bmake deinstall` — install/uninstall the binary package.
- `bmake check` — run pkg_install checks (with tests disabled via
  `LLAMA_BUILD_TESTS=NO` there are no unit tests).
- `bmake print-PLIST` — regenerate PLIST (uses the `PRINT_PLIST_AWK`/`PLIST_SUBST`
  machinery above; verify the `${LLAMA_BUILD_NUMBER}` substitution still applies).
- `bmake url2pkg` — not useful here (package predates it).
- `bmake resolve-depends` — check dependency availability.
- After editing `Makefile` concerns: `bmake show-vars` to inspect what's set.
- Committing is done from the `wip` tree root (`/bd/pkgsrc/wip` is a git repo;
  the package dir itself is not). Commit messages follow pkgsrc wip style, e.g.
  `llama.cpp: update to 0.0.2.10276.` — see `git log --oneline -- llama.cpp/`.

## Updating the package (release bump workflow)

1. Pick the new upstream tag `bN` and commit hash from
   https://github.com/ggml-org/llama.cpp/releases.
2. In `Makefile.common`: update `LLAMA_BUILD_NUMBER` and `LLAMA_BUILD_COMMIT`.
   `GITHUB_TAG` derives from the number automatically.
3. Fetch the new source tarball and UI tarball; run `bmake makesum` (or update
   `distinfo` manually with BLAKE2s/SHA512/Size for both files).
4. `bmake clean && bmake` — rebuild from scratch.
5. Check `PLIST` for new/removed binaries with `bmake print-PLIST`; update
   `PLIST` as needed (keeping `${LLAMA_BUILD_NUMBER}` unexpanded in llama lib
   names, but hardcoding the bundled ggml version for `libggml*`, e.g.
   `0.18.1`).
6. If upstream moved/removed a `cmake` option or changed bundled ggml usage,
   adjust `CMAKE_CONFIGURE_ARGS` (the bundled ggml builds from `ggml/`; no
   `math/ggml` dependency is used).
7. Commit from `/bd/pkgsrc/wip` with a message like
   `llama.cpp: update to 0.0.2.10276.`

## Gotchas / non-obvious things

- **Do not touch `work/`.** It contains the full upstream source (with its own
  `AGENTS.md`/`CLAUDE.md`) plus extracted `llama-*-ui` and the generated
  `_gzip/` PWA app. Any patch you want to ship must go in `patches/` and be
  registered in `distinfo` (SHA1) — see `patches/patch-vendor_sheredom_subprocess.h`,
  which fixes a NetBSD `posix_spawn_file_actions_addchdir` build failure.
- The NetBSD patch is the only reason the package builds on NetBSD: upstream
  gates `posix_spawn_file_actions_addchdir` behind Apple-only `#if`, the patch
  adds `defined(__NetBSD__)` (upstream PR sheredom/subprocess.h#102).
- The `TODO` file lists 12 known CVEs (e.g. CVE-2026-17500) with no fixes yet;
  they are the reason the package keeps getting updated. Reference them in
  commit messages when bumping (repo history does this).
- `Makefile` sets `CATEGORIES= devel` and `LICENSE= mit`; upstream's full
  license check: llama.cpp is MIT, but `gguf-py` and the web UI ship
  separately — do not add their licenses to `LICENSE` for the C++ package.
- The `work/` UI tarball contains PWA assets (`apple-splash-*`), which have
  their own licenses; they are installed as static assets under the server, not
  listed in `PLIST`.
- `git status`/`git log` only work from `/bd/pkgsrc/wip`, not from this dir.
- `PKGNAME` in `Makefile` is deliberately squatting the `0.0.2` prefix so the
  `libllama*.so` ABI version resolves correctly; don't "simplify" it.
- `LLAMA_CPP_VAR` is defined in `Makefile` (not `Makefile.common`) — it's a hack
  and must stay in sync manually if you ever move it.
