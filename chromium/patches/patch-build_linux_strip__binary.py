$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- build/linux/strip_binary.py.orig	2025-07-29 22:51:44.000000000 +0000
+++ build/linux/strip_binary.py
@@ -10,6 +10,7 @@ import sys
 
 
 def main() -> int:
+  return 0
   parser = argparse.ArgumentParser(description="Strip binary using LLVM tools.")
   parser.add_argument("--llvm-strip-binary-path",
                       help="Path to llvm-strip executable.")
