$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/doc/api/cli.md.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/doc/api/cli.md
@@ -2920,7 +2920,6 @@ V8 options that are allowed are:
 * `--disallow-code-generation-from-strings`
 * `--enable-etw-stack-walking`
 * `--expose-gc`
-* `--huge-max-old-generation-size`
 * `--interpreted-frames-native-stack`
 * `--jitless`
 * `--max-old-space-size`
