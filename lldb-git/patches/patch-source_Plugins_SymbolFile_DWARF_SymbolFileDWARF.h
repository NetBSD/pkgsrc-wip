$NetBSD$

--- source/Plugins/SymbolFile/DWARF/SymbolFileDWARF.h.orig	2017-02-02 23:56:41.000000000 +0000
+++ source/Plugins/SymbolFile/DWARF/SymbolFileDWARF.h
@@ -21,6 +21,7 @@
 
 // Other libraries and framework includes
 #include "llvm/ADT/DenseMap.h"
+#include "llvm/Support/Threading.h"
 
 #include "lldb/Core/Flags.h"
 #include "lldb/Core/RangeMap.h"
@@ -305,7 +306,7 @@ protected:
   typedef llvm::DenseMap<lldb::opaque_compiler_type_t, DIERef> ClangTypeToDIE;
 
   struct DWARFDataSegment {
-    std::once_flag m_flag;
+    llvm::once_flag m_flag;
     lldb_private::DWARFDataExtractor m_data;
   };
 
