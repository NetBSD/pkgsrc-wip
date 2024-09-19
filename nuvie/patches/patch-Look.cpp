$NetBSD$

"Fixes for C++11 support" from upstream.

--- Look.cpp.orig	2012-07-06 18:54:24.000000000 +0000
+++ Look.cpp
@@ -37,7 +37,7 @@ Look::Look(Configuration *cfg)
 {
  config = cfg;
 
- look_tbl[2047] = '\0';
+ look_tbl[2047] = NULL;
  max_len = 0;
 }
 
