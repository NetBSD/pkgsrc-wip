$NetBSD: patch-tests_torture.c,v 1.1 2020/01/06 12:04:13 pho Exp $

Fix build on NetBSD 8.1: Don't try to use PATH_MAX without #include <limits.h>

--- tests/torture.c.orig	2026-07-16 10:48:05.000000000 +0000
+++ tests/torture.c
@@ -24,6 +24,7 @@
 #include "config.h"
 #include "tests_config.h"
 #include <fcntl.h>
+#include <limits.h>
 #include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
