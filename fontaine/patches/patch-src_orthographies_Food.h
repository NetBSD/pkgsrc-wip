$NetBSD$


--- /dev/null	2015-01-22 14:05:28.000000000 -0600
+++ src/orthographies/Food.h	2015-01-22 14:06:40.000000000 -0600
@@ -0,0 +1,52 @@
+//
+// Food.h
+//
+
+#ifndef ORTHOGRAPHY_DATA
+#include "../OrthographyData.h"
+#endif
+
+#ifndef FOOD
+#define FOOD
+
+namespace Food{
+
+//
+// Unicode values 
+//
+UINT32 values[]={
+	0x2615,
+	0x26FE,
+	START_RANGE_PAIR,
+	0x1F33D,0x1F33F,
+	START_RANGE_PAIR,
+	0x1F344,0x1F37D,
+	END_OF_DATA
+};
+
+//
+// Sample sentences
+// 
+const char *sentences[]={
+	"",
+	END_OF_DATA
+};
+
+
+//
+// 
+//
+OrthographyData data={
+	"Food and Drink", // Common name
+	"Food and Drink", // Native name
+	0x2615, // key
+	values,
+	"",// Sample characters
+	sentences
+};
+
+const OrthographyData *pData = &data;
+
+}; // end of namespace
+
+#endif
