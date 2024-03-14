$NetBSD$

include cstring for strcmp()
include memory for std::unique_ptr<>

--- examples/lua.hpp.orig	2024-03-13 18:32:59.378866419 +0000
+++ examples/lua.hpp
@@ -7,6 +7,8 @@
 #include <cstdlib>
 #include <cstdio>
 #include <cstdint>
+#include <cstring>
+#include <memory>
 #include <string>
 #include <set>
 #include <stack>
