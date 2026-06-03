$NetBSD$

struct enum_list has a new C member, allow for that.

--- src/netsnmpy/netsnmp_ffi.py.orig	2026-06-02 10:39:28.297081941 +0000
+++ src/netsnmpy/netsnmp_ffi.py
@@ -270,6 +270,7 @@ struct enum_list {{
     struct enum_list *next;
     int             value;
     char           *label;
+    ...;
 }};
 
 struct tree {{
