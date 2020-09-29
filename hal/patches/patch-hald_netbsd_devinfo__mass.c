$NetBSD$

--- hald/netbsd/devinfo_mass.c.orig	2018-09-22 22:22:46.346651150 +0000
+++ hald/netbsd/devinfo_mass.c
@@ -41,6 +41,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <paths.h>
+#include <sys/stat.h>
 #include <unistd.h>
 
 #include "../osspec.h"
