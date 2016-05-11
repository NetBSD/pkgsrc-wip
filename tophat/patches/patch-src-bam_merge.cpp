$NetBSD$

# Missing header
--- src/bam_merge.cpp.orig	2016-02-14 18:21:17.113079000 +0000
+++ src/bam_merge.cpp
@@ -1,3 +1,4 @@
+#include <getopt.h>
 #include "bam_merge.h"
 
 #define USAGE "Usage: bam_merge [-Q] <out.bam> <in1.bam> <in2.bam> [...]\n"
