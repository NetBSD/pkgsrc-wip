$NetBSD$

Add missing include for new boost version.

--- src/slic3r/Config/Version.cpp.orig	2024-07-04 02:06:21.971201848 +0000
+++ src/slic3r/Config/Version.cpp
@@ -6,6 +6,7 @@
 
 #include <cctype>
 
+#include <boost/filesystem/directory.hpp>
 #include <boost/filesystem/operations.hpp>
 #include <boost/nowide/fstream.hpp>
 
