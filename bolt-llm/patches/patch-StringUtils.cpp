$NetBSD$

# Missing header
--- StringUtils.cpp.orig	2017-08-02 23:43:24 UTC
+++ StringUtils.cpp
@@ -22,6 +22,7 @@
 #include <cstdio>
 #include <iostream>
 #include <sstream>
+#include <sys/types.h>	// uint
 
 #include "StringUtils.hpp"
 
