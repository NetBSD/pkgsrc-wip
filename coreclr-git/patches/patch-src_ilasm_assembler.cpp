$NetBSD$

--- src/ilasm/assembler.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/ilasm/assembler.cpp
@@ -952,7 +952,7 @@ BOOL Assembler::EmitField(FieldDescripto
             lVal /= sizeof(WCHAR);
 
 #if defined(ALIGN_ACCESS) || BIGENDIAN
-            void* pValueTemp = _alloca(lVal * sizeof(WCHAR));
+            void* pValueTemp = Alloca(lVal * sizeof(WCHAR));
             memcpy(pValueTemp, pValue, lVal * sizeof(WCHAR));
             pValue = pValueTemp;
 
