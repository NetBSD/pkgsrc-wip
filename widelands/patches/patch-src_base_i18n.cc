$NetBSD: patch-src_base_i18n.cc,v 1.2 2020/07/27 15:21:43 nia Exp $

Include clocale unconditionally.

Undefine any *gettext macros to avoid infinite recursion.

https://github.com/widelands/widelands/issues/6488

--- src/base/i18n.cc.orig	2024-03-28 10:12:05.000000000 +0000
+++ src/base/i18n.cc
@@ -20,9 +20,7 @@
 
 #include "base/i18n.h"
 
-#ifdef __FreeBSD__
 #include <clocale>
-#endif
 
 #include <cstdlib>
 #include <map>
@@ -46,6 +44,12 @@
 #endif
 #endif
 
+// If eg. pgettext_expr happens to be a macro back to pgettext, we need
+// to clear these to avoid infinite recursion.
+#undef pgettext
+#undef ngettext
+#undef npgettext
+
 namespace i18n {
 
 /// A stack of textdomains. On entering a new textdomain, the old one gets
