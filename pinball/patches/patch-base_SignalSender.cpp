$NetBSD$

--- base/SignalSender.cpp.orig	2003-11-20 16:46:16.000000000 +0000
+++ base/SignalSender.cpp
@@ -6,7 +6,7 @@
     email                : henqvist@excite.com
  ***************************************************************************/
 
-
+#include <cstddef>
 #include "Private.h"
 #include "SignalSender.h"
 #include "Group.h"
