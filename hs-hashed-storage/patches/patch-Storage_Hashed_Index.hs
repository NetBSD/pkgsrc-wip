$NetBSD: patch-Storage_Hashed_Index.hs,v 1.1 2013/12/04 10:12:19 phonohawk Exp $

'Bits a' no longer implies 'Num a' on recent base libraries.

--- Storage/Hashed/Index.hs.orig	2013-12-04 10:05:57.000000000 +0000
+++ Storage/Hashed/Index.hs
@@ -152,11 +152,11 @@ itemIsDir :: Item -> Bool
 itemIsDir i = unsafeHead (iDescriptor i) == c2w 'D'
 
 -- xlatePeek32 = fmap xlate32 . peek
-xlatePeek64 :: (Storable a, Bits a) => Ptr a -> IO a
+xlatePeek64 :: (Storable a, Bits a, Num a) => Ptr a -> IO a
 xlatePeek64 = fmap xlate64 . peek
 
 -- xlatePoke32 ptr v = poke ptr (xlate32 v)
-xlatePoke64 :: (Storable a, Bits a) => Ptr a -> a -> IO ()
+xlatePoke64 :: (Storable a, Bits a, Num a) => Ptr a -> a -> IO ()
 xlatePoke64 ptr v = poke ptr (xlate64 v)
 
 -- | Lay out the basic index item structure in memory. The memory location is
