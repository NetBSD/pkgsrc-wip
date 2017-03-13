$NetBSD$

--- source/Core/FormatEntity.cpp.orig	2017-02-04 18:35:35.000000000 +0000
+++ source/Core/FormatEntity.cpp
@@ -1187,7 +1187,8 @@ bool FormatEntity::Format(const Entry &e
                                               ? arch.GetTriple().getOS()
                                               : llvm::Triple::UnknownOS;
             if ((ostype == llvm::Triple::FreeBSD) ||
-                (ostype == llvm::Triple::Linux)) {
+                (ostype == llvm::Triple::Linux) ||
+                (ostype == llvm::Triple::NetBSD)) {
               format = "%" PRIu64;
             }
           } else {
