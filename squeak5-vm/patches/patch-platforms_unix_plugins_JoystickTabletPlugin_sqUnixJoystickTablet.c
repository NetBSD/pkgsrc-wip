$NetBSD$

--- platforms/unix/plugins/JoystickTabletPlugin/sqUnixJoystickTablet.c.orig	2022-06-02 14:10:44.000000000 +0000
+++ platforms/unix/plugins/JoystickTabletPlugin/sqUnixJoystickTablet.c
@@ -29,6 +29,7 @@
 /* Author: davidf@afeka.ac.il
  */
 
+#if __linux__
 #include <assert.h>
 #include <limits.h>
 #include <stdio.h>
@@ -354,3 +355,41 @@ int tabletResultSize(void)
   return 0;
 }
 
+#else
+#include "sq.h"
+#include "JoystickTabletPlugin.h"
+
+/* we don't have any joysticks */
+
+void *joySticks= 0;
+
+int joystickRead(int index)	{ return 0; }
+int joystickInit(void)		{ return 0; }
+
+/* we don't have any tablets either */
+
+int tabletInit(void)
+{
+  return 0;
+}
+
+int tabletGetParameters(int cursorIndex, int result[])
+{
+  return 0;
+}
+
+int tabletRead(int cursorIndex, int result[])
+{
+  return 0;
+}
+
+int tabletResultSize(void)
+{
+  return 0;
+}
+
+int joystickShutdown(void)
+{
+  return 0;
+}
+#endif	/* __linux__ */
