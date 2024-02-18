$NetBSD$

--- platforms/unix/plugins/JoystickTabletPlugin/sqUnixJoystickTablet.c.orig	2023-12-18 14:41:18.000000000 +0000
+++ platforms/unix/plugins/JoystickTabletPlugin/sqUnixJoystickTablet.c
@@ -32,6 +32,7 @@
 
 #include "sq.h"
 
+#if __linux__
 #include <assert.h>
 #include <stdint.h>
 #include <sys/ioctl.h>
@@ -348,6 +349,44 @@ int tabletRead(int cursorIndex, int resu
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
 int tabletResultSize(void)
 {
   return 0;
