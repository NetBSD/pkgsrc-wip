$NetBSD$

# Portability

--- src/StringUtils.cpp.orig	2019-05-24 15:09:56.720778471 +0000
+++ src/StringUtils.cpp
@@ -22,6 +22,7 @@
 #include <cstdio>
 #include <iostream>
 #include <sstream>
+#include <sys/types.h>	// uint
 
 #include "StringUtils.hpp"
 
