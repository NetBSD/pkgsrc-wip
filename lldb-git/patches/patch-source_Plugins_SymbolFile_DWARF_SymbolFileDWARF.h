$NetBSD$

--- source/Plugins/SymbolFile/DWARF/SymbolFileDWARF.h.orig	2016-09-10 17:36:23.000000000 +0000
+++ source/Plugins/SymbolFile/DWARF/SymbolFileDWARF.h
@@ -305,7 +305,6 @@ protected:
   typedef llvm::DenseMap<lldb::opaque_compiler_type_t, DIERef> ClangTypeToDIE;
 
   struct DWARFDataSegment {
-    std::once_flag m_flag;
     lldb_private::DWARFDataExtractor m_data;
   };
 
