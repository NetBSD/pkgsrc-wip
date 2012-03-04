$NetBSD: patch-compiler_nativeGen_AsmCodeGen.lhs,v 1.1 2012/03/04 04:37:13 phonohawk Exp $

For systems having as(1) that doesn't recognise .ident
directives. (Already merged to the upstream)


--- compiler/nativeGen/AsmCodeGen.lhs.orig	2012-02-01 18:10:32.000000000 +0000
+++ compiler/nativeGen/AsmCodeGen.lhs
@@ -525,12 +525,15 @@ makeImportsDoc dflags imports
             (if platformHasGnuNonexecStack (targetPlatform dflags)
              then Pretty.text ".section .note.GNU-stack,\"\",@progbits"
              else Pretty.empty)
+            Pretty.$$
                 -- And just because every other compiler does, lets stick in
                 -- an identifier directive: .ident "GHC x.y.z"
-            Pretty.$$ let compilerIdent = Pretty.text "GHC" Pretty.<+>
-	                                  Pretty.text cProjectVersion
-                       in Pretty.text ".ident" Pretty.<+>
-                          Pretty.doubleQuotes compilerIdent
+            (if platformHasIdentDirective (targetPlatform dflags)
+             then let compilerIdent = Pretty.text "GHC" Pretty.<+>
+	                              Pretty.text cProjectVersion
+                   in Pretty.text ".ident" Pretty.<+>
+                      Pretty.doubleQuotes compilerIdent
+             else Pretty.empty)
 
  where
 	-- Generate "symbol stubs" for all external symbols that might
