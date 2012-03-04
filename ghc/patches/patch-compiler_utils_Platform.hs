$NetBSD: patch-compiler_utils_Platform.hs,v 1.1 2012/03/04 04:37:13 phonohawk Exp $

For systems having as(1) that doesn't recognise .ident
directives. (Already merged to the upstream)


--- compiler/utils/Platform.hs.orig	2012-02-01 18:10:32.000000000 +0000
+++ compiler/utils/Platform.hs
@@ -22,6 +22,7 @@ data Platform
               platformOS                       :: OS,
               platformWordSize                 :: {-# UNPACK #-} !Int,
               platformHasGnuNonexecStack       :: Bool,
+              platformHasIdentDirective        :: Bool,
               platformHasSubsectionsViaSymbols :: Bool
           }
         deriving (Read, Show, Eq)
