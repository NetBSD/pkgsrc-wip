$NetBSD$

For memmove().

--- security/pkix/lib/pkixnames.cpp.orig	2016-03-19 10:59:41.602327520 +0000
+++ security/pkix/lib/pkixnames.cpp
@@ -37,6 +37,8 @@
 #include "pkixcheck.h"
 #include "pkixutil.h"
 
+#include <string.h>
+
 namespace mozilla { namespace pkix {
 
 namespace {
