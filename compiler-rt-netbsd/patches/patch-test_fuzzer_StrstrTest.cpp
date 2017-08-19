$NetBSD$

--- test/fuzzer/StrstrTest.cpp.orig	2017-08-19 18:02:19.288692067 +0000
+++ test/fuzzer/StrstrTest.cpp
@@ -0,0 +1,28 @@
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+
+// Test strstr and strcasestr hooks.
+#include <cstdint>
+#include <cstdio>
+#include <cstdlib>
+#include <string.h>
+#include <string>
+
+// Windows does not have strcasestr and memmem, so we are not testing them.
+#ifdef _WIN32
+#define strcasestr strstr
+#define memmem(a, b, c, d) true
+#endif
+
+extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
+  if (Size < 4) return 0;
+  std::string s(reinterpret_cast<const char*>(Data), Size);
+  if (strstr(s.c_str(), "FUZZ") &&
+      strcasestr(s.c_str(), "aBcD") &&
+      memmem(s.data(), s.size(), "kuku", 4)
+      ) {
+    fprintf(stderr, "BINGO\n");
+    exit(1);
+  }
+  return 0;
+}
