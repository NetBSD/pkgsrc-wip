$NetBSD$


--- /dev/null	2015-01-23 12:43:49.000000000 -0600
+++ src/orthographies/MathematicalNumerals.h	2015-01-23 11:48:40.000000000 -0600
@@ -0,0 +1,58 @@
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
+// MathematicalNumerals.h
+//
+
+#ifndef ORTHOGRAPHY_DATA
+#include "../OrthographyData.h"
+#endif
+
+#ifndef MATH_NUMERALS
+#define MATH_NUMERALS
+
+namespace MathematicalNumerals{
+
+//
+// Unicode values 
+//
+UINT32 values[]={
+	START_RANGE_PAIR,
+	0x1D7CE,0x1D7FF,
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
+	"Mathematical Numerals", // Common name
+	"Mathematical Numerals", // Native name
+	0x1D7D1, // key
+	values,
+	"", // Sample characters
+	sentences
+};
+
+const OrthographyData *pData = &data;
+
+}; // end of namespace
+
+#endif
