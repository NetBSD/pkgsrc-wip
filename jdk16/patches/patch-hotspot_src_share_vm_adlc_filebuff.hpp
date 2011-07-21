$NetBSD: patch-hotspot_src_share_vm_adlc_filebuff.hpp,v 1.1 2011/07/21 06:07:06 ftigeot Exp $

--- hotspot/src/share/vm/adlc/filebuff.hpp.orig	2007-09-25 04:19:15 +0000
+++ hotspot/src/share/vm/adlc/filebuff.hpp
@@ -8,11 +8,7 @@
 
 // FILEBUFF.HPP - Definitions for parser file buffering routines
 
-#if _MSC_VER >= 1300  // Visual C++ 7.0 or later
 #include <iostream>
-#else
-#include <iostream.h>
-#endif
 
 // STRUCTURE FOR HANDLING INPUT AND OUTPUT FILES
 typedef struct {
@@ -60,6 +56,8 @@ class FileBuff {
   int getoff(const char *s) { return _bufoff+(int)(s-_buf); }
 };
 
+using namespace std;
+
 //------------------------------FileBuffRegion---------------------------------
 // A buffer region is really a region of some file, specified as a linked list
 // of offsets and lengths.  These regions can be merged; overlapping regions
