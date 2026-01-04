$NetBSD$

* Fix ctype(3) tolower usage

--- sdk/src/syncfilter.cpp.orig	2026-01-03 22:42:24.434490944 +0000
+++ sdk/src/syncfilter.cpp
@@ -980,7 +980,7 @@ bool add(const string& text, SizeFilterP
     {
         std::uint64_t shift = 0;
 
-        switch (std::tolower(istream.get()))
+        switch (std::tolower(static_cast<unsigned char>(istream.get())))
         {
         case 'k':
             // Kilobytes.
