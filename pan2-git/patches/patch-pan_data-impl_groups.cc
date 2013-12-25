$NetBSD: patch-pan_data-impl_groups.cc,v 1.1 2013/12/25 14:06:34 thomasklausner Exp $

Fix build with libc++.
From joerg@

--- pan/data-impl/groups.cc.orig	2013-12-21 12:39:52.000000000 +0000
+++ pan/data-impl/groups.cc
@@ -81,7 +81,7 @@ namespace
   }
 }
 
-#include <ext/algorithm>
+#include <algorithm>
 
 void
 DataImpl :: load_newsrc (const Quark       & server,
