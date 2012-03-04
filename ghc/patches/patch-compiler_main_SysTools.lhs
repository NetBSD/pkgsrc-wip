$NetBSD: patch-compiler_main_SysTools.lhs,v 1.1 2012/03/04 04:37:13 phonohawk Exp $

For systems having as(1) that doesn't recognise .ident
directives. (Already merged to the upstream)


--- compiler/main/SysTools.lhs.orig	2012-02-01 18:10:32.000000000 +0000
+++ compiler/main/SysTools.lhs
@@ -194,6 +194,7 @@ initSysTools mbMinusB
         ; targetOS <- readSetting "target os"
         ; targetWordSize <- readSetting "target word size"
         ; targetHasGnuNonexecStack <- readSetting "target has GNU nonexec stack"
+        ; targetHasIdentDirective <- readSetting "target has .ident directive"
         ; targetHasSubsectionsViaSymbols <- readSetting "target has subsections via symbols"
         ; myExtraGccViaCFlags <- getSetting "GCC extra via C opts"
         -- On Windows, mingw is distributed with GHC,
@@ -259,6 +260,7 @@ initSysTools mbMinusB
                                               platformOS   = targetOS,
                                               platformWordSize = targetWordSize,
                                               platformHasGnuNonexecStack = targetHasGnuNonexecStack,
+                                              platformHasIdentDirective = targetHasIdentDirective,
                                               platformHasSubsectionsViaSymbols = targetHasSubsectionsViaSymbols
                                           },
                         sTmpDir = normalise tmpdir,
