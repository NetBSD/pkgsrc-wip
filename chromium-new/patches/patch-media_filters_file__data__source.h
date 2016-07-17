$NetBSD$

--- media/filters/file_data_source.h.orig	2016-06-24 01:02:23.000000000 +0000
+++ media/filters/file_data_source.h
@@ -7,6 +7,7 @@
 
 #include <stdint.h>
 
+#include <cstdio>
 #include <string>
 
 #include "base/files/file.h"
