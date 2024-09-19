$NetBSD$

Include <stdarg.h> for va_list.

--- src/fsa/logger.hpp.orig	2024-08-06 21:51:50.094015916 +0000
+++ src/fsa/logger.hpp
@@ -2,6 +2,7 @@
 #define FSA_LOGGER_HPP
 
 
+#include <stdarg.h>  
 #include <stdio.h>
 #include <map>
 #include <string>
