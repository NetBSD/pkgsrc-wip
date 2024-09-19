$NetBSD$

tidy-5.x compatibility.

--- konq-plugins/validators/tidy_validator.cpp.orig	2016-03-25 06:39:47.000000000 +0000
+++ konq-plugins/validators/tidy_validator.cpp
@@ -25,8 +25,8 @@
 
 #include <kdebug.h>
 
-#include <buffio.h>
 #include <tidy.h>
+#include <tidybuffio.h>
 
 #include <config-konq-validator.h>
 
