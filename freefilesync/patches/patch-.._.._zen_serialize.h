$NetBSD$

Add missing header for sysconf(3).

--- ../../zen/serialize.h.orig	2024-01-28 13:49:07.264863552 +0000
+++ ../../zen/serialize.h
@@ -8,6 +8,7 @@
 #define SERIALIZE_H_839405783574356
 
 #include <functional>
+#include <unistd.h>
 #include "sys_error.h"
 //keep header clean from specific stream implementations! (e.g.file_io.h)! used by abstract.h!
 
