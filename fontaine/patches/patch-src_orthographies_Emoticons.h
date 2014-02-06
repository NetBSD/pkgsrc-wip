--- /dev/null	2014-02-05 21:17:19.000000000 -0600
+++ src/orthographies/Emoticons.h	2014-02-05 21:33:06.000000000 -0600
@@ -0,0 +1,63 @@
+//
+// The Fontaine Font Analysis Project 
+// 
+// Copyright (c) 2009 by Edward H. Trager
+// All Rights Reserved
+// 
+// Released under the GNU GPL version 2.0 or later.
+//     
+
+
+//
+// Emoticons.h
+//
+
+#ifndef ORTHOGRAPHY_DATA
+#include "../OrthographyData.h"
+#endif
+
+#ifndef EMOTICONS
+#define EMOTICONS
+
+namespace Emoticons{
+
+//
+// Unicode values 
+//
+UINT32 values[]={
+	START_RANGE_PAIR,
+	0x2639,0x263B, // Miscellaneous Symbols
+	START_RANGE_PAIR,
+	0x1F600,0x1F642, // Emoticons
+	START_RANGE_PAIR,
+	0x1F645,0x1F64F, // Emoticons
+	END_OF_DATA
+};
+
+//
+// Sample sentences
+// 
+const char *sentences[]={
+	"",
+	"",
+	END_OF_DATA
+};
+
+
+//
+// 
+//
+OrthographyData data={
+	"Emoticons",
+	"Emoticons",
+	0x263A, // WHITE SMILING FACE
+	values,
+	"",
+	sentences
+};
+
+const OrthographyData *pData = &data;
+
+}; // end of namespace
+
+#endif
