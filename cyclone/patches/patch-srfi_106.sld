$NetBSD$

This patch defines *ai-v4mapped* to zero when AI_V4MAPPED is undefined
and similarly for *ai-all* (similar to other patches). This allows
(srfi 106) to be available on NetBSD and other platforms without
AI_V4MAPPED and is the recommended behaviour by the author of SRFI-106:

https://srfi-email.schemers.org/srfi-106/msg/2762553/

Merged upstream in commit 706f7ef2a85aaa0b4ec13ce0139ff8e7dd9b9f10.

--- srfi/106.sld.orig	2024-02-14 02:31:23.000000000 +0000
+++ srfi/106.sld
@@ -388,7 +388,7 @@
 #ifdef AI_V4MAPPED
       return_closcall1(data, k, obj_int2obj(AI_V4MAPPED)); 
 #else
-      Cyc_rt_raise_msg(data, \"AI_V4MAPPED is not available on this platform\");
+      return_closcall1(data, k, obj_int2obj(0)); 
 #endif
       ")
     (define *ai-all* (ai-all))
@@ -398,7 +398,7 @@
 #ifdef AI_ALL
       return_closcall1(data, k, obj_int2obj(AI_ALL)); 
 #else
-      Cyc_rt_raise_msg(data, \"AI_ALL is not available on this platform\");
+      return_closcall1(data, k, obj_int2obj(0)); 
 #endif
       ")
     (make-const ai-addrconfig  "AI_ADDRCONFIG" )
