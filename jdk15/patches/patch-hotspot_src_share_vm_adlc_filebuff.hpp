$NetBSD: patch-hotspot_src_share_vm_adlc_filebuff.hpp,v 1.1 2011/07/21 19:15:31 ftigeot Exp $

--- hotspot/src/share/vm/adlc/filebuff.hpp.orig	2008-05-28 07:01:18 +0000
+++ hotspot/src/share/vm/adlc/filebuff.hpp
@@ -10,7 +10,7 @@
 
 // FILEBUFF.HPP - Definitions for parser file buffering routines
 
-#include <iostream.h>
+#include <iostream>
 
 // STRUCTURE FOR HANDLING INPUT AND OUTPUT FILES
 typedef struct {
@@ -58,6 +58,8 @@ class FileBuff {
   int getoff(const char *s) { return _bufoff+(int)(s-_buf); }
 };
 
+using namespace std;
+
 //------------------------------FileBuffRegion---------------------------------
 // A buffer region is really a region of some file, specified as a linked list
 // of offsets and lengths.  These regions can be merged; overlapping regions
