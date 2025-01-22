$NetBSD$

Add missing header.

--- src/qso_db.cpp.orig	2007-02-16 20:19:59.000000000 +0000
+++ src/qso_db.cpp
@@ -1,3 +1,4 @@
+#include <cstring>
 #include <stdlib.h>
 #include <ctype.h>
 #include "qso_db.h"
