$NetBSD: patch-util__pidfile.hpp,v 1.1 2012/04/25 09:07:50 fhajny Exp $

Fix build with GCC 4.7.
--- util/pidfile.hpp.orig	2011-08-17 15:38:30.000000000 +0000
+++ util/pidfile.hpp
@@ -38,6 +38,7 @@
 #pragma once
 
 #include <string>
+#include "unistd.h"
 
 namespace datadifferential {
 namespace util {
