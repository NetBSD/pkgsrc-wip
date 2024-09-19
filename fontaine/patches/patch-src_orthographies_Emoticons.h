$NetBSD$


--- /dev/null	2014-02-10 10:19:28.000000000 -0600
+++ src/orthographies/Emoticons.h	2014-02-10 10:36:24.000000000 -0600
@@ -0,0 +1,81 @@
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
+// consisting of faces, hearts, gestures, kisses, and two truly abstract
+// symbols only, lest it expand to include every pictograph and dingbat in 
+// Unicode
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
+	0x2661,
+	0x2665,
+	START_RANGE_PAIR,
+	0x270A,0x270C, // Dingbats
+	0x2764,
+	START_RANGE_PAIR,
+	0x1F44A,0x1F44F, // Misc. Symbols and Pictographs
+	0x1F48B,
+	0x1F48F,
+	START_RANGE_PAIR,
+	0x1F494,0x1F49C,
+	0x1F4A2,
+	0x1F4AB, 
+	START_RANGE_PAIR,
+	0x1F58F,0x1F596,
+	START_RANGE_PAIR,
+	0x1F600,0x1F642, // Emoticons
+	START_RANGE_PAIR,
+	0x1F645,0x1F64F,
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
