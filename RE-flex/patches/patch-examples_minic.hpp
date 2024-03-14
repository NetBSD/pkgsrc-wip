$NetBSD$

include cstring for strcmp()

--- examples/minic.hpp.orig	2024-03-13 18:36:35.967481074 +0000
+++ examples/minic.hpp
@@ -9,6 +9,7 @@
 #include <cstdlib>
 #include <cstdio>
 #include <cstdint>
+#include <cstring>
 #include <string>
 #include <map>
 #include <set>
