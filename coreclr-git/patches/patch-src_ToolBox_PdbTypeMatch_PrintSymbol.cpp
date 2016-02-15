$NetBSD$

--- src/ToolBox/PdbTypeMatch/PrintSymbol.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/ToolBox/PdbTypeMatch/PrintSymbol.cpp
@@ -1546,7 +1546,7 @@ void PrintType(IDiaSymbol *pSymbol)
         }
 
         if (pSymbol->get_types(0, &count, NULL) == S_OK) {
-          IDiaSymbol** rgpDiaSymbols = (IDiaSymbol**) _alloca(sizeof(IDiaSymbol *) * count);
+          IDiaSymbol** rgpDiaSymbols = (IDiaSymbol**) Alloca(sizeof(IDiaSymbol *) * count);
 
           if (pSymbol->get_types(count, &count, rgpDiaSymbols) == S_OK) {
             for (ULONG i = 0; i < count; i++) {
