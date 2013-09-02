$NetBSD: patch-library-trans-ip_C__TransIP.cpp,v 1.1 2013/09/02 19:08:25 thomasklausner Exp $

Add header for str*, mem* prototypes.

--- library-trans-ip/C_TransIP.cpp.orig	2010-10-27 12:30:16.000000000 +0000
+++ library-trans-ip/C_TransIP.cpp
@@ -21,6 +21,7 @@
 #include "Utils.hpp"
 
 #include <cerrno>
+#include <string.h>
 #include <unistd.h>
 
 #include <regex.h>
