$NetBSD$

GCC 13 fixes.

--- toolkit/components/telemetry/pingsender/pingsender.cpp.orig	2023-05-12 14:19:10.322882448 +0200
+++ toolkit/components/telemetry/pingsender/pingsender.cpp	2023-05-12 14:19:26.908660689 +0200
@@ -3,6 +3,7 @@
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
+#include <cstdint>
 #include <cstdlib>
 #include <cstring>
 #include <ctime>
