$NetBSD: patch-Storage_Hashed_Utils.hs,v 1.1 2013/12/04 10:12:19 phonohawk Exp $

'Bits a' no longer implies 'Num a' on recent base libraries.

--- Storage/Hashed/Utils.hs.orig	2013-12-04 10:03:59.000000000 +0000
+++ Storage/Hashed/Utils.hs
@@ -92,8 +92,8 @@ align boundary i = case i `rem` boundary
                      x -> i + boundary - x
 {-# INLINE align #-}
 
-xlate32 :: (Bits a) => a -> a
-xlate64 :: (Bits a) => a -> a
+xlate32 :: (Bits a, Num a) => a -> a
+xlate64 :: (Bits a, Num a) => a -> a
 
 #ifdef LITTLEENDIAN
 xlate32 = id
@@ -101,7 +101,7 @@ xlate64 = id
 #endif
 
 #ifdef BIGENDIAN
-bytemask :: (Bits a) => a
+bytemask :: (Bits a, Num a) => a
 bytemask = 255
 
 xlate32 a = ((a .&. (bytemask `shift`  0)) `shiftL` 24) .|.
