$NetBSD$

Fix for building with clang.
https://bugzilla.gnome.org/attachment.cgi?id=324116&action=edit

--- pan/data-impl/groups.cc.orig	2015-11-15 00:23:37.000000000 +0000
+++ pan/data-impl/groups.cc
@@ -81,7 +81,14 @@ namespace
   }
 }
 
+#include <ciso646> // detect std::lib
+#ifdef _LIBCPP_VERSION
+// using libc++
+#include <algorithm>
+#else
+// using libstdc++
 #include <ext/algorithm>
+#endif
 
 void
 DataImpl :: load_newsrc (const Quark       & server,
