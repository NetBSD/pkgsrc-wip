$NetBSD$

Include missing stdarg.h

--- Settings.c.orig	2024-06-29 01:19:30.776151045 +0000
+++ Settings.c
@@ -14,6 +14,7 @@ in the source distribution for its full 
 #include <fcntl.h>
 #include <limits.h>
 #include <pwd.h>
+#include <stdarg.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
