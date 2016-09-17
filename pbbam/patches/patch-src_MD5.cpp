$NetBSD$

# Use external ssl

--- src/MD5.cpp.orig	2016-07-12 16:00:45 UTC
+++ src/MD5.cpp
@@ -40,7 +40,7 @@
 // Author: Brett Bowman
 
 #include "pbbam/MD5.h"
-#include <cram/md5.h>
+#include <openssl/md5.h>
 
 namespace PacBio {
 namespace BAM {
