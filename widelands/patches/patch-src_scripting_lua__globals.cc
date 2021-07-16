$NetBSD$

Provide dnpgettext_expr() with 5 parameters on NetBSD.
The header "include/libintl.h" provides a macro that does not work.

--- src/scripting/lua_globals.cc.orig	2021-06-14 09:22:20.000000000 +0000
+++ src/scripting/lua_globals.cc
@@ -36,6 +36,14 @@
 #include "scripting/lua_table.h"
 #include "scripting/report_error.h"
 
+
+// pkgsrc patch for NetBSD
+#ifdef __NetBSD__
+#define dnpgettext_expr(domainname, msgctxt, msgid, msgidPlural, n) \
+    dcnpgettext_expr((domainname), (msgctxt), (msgid), (msgidPlural), (n), (LC_MESSAGES))
+#endif
+
+
 namespace LuaGlobals {
 
 /* RST
