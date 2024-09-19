$NetBSD: patch-common_string__t.hpp,v 1.1 2013/09/02 19:08:24 thomasklausner Exp $

Include header for strstr() etc. prototypes.

--- common/string_t.hpp.orig	2010-10-27 12:30:16.000000000 +0000
+++ common/string_t.hpp
@@ -21,6 +21,7 @@
 #define _STRING_T_HPP
 
 #include <string>
+#include <string.h>
 
 #if defined(__hpux)
 #define string_t  string
