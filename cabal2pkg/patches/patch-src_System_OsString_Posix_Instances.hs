$NetBSD$

Fix build with GHC 9.10

--- src/System/OsString/Posix/Instances.hs.orig	2025-02-02 07:36:16.634791582 +0000
+++ src/System/OsString/Posix/Instances.hs
@@ -3,7 +3,7 @@
 module System.OsString.Posix.Instances () where
 
 import Data.CaseInsensitive (FoldCase(..))
-import System.OsPath.Data.ByteString.Short (fromShort, toShort)
+import System.OsString.Data.ByteString.Short (fromShort, toShort)
 import System.OsString.Internal.Types (PosixString(..))
 
 instance FoldCase PosixString where
