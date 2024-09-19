$NetBSD: patch-Data_Vector_Storable_ByteString_Internal.hs,v 1.1 2013/02/23 15:58:08 phonohawk Exp $

vector-0.10.* has NFData instance for Vector.


--- Data/Vector/Storable/ByteString/Internal.hs.orig	2013-02-23 15:44:47.000000000 +0000
+++ Data/Vector/Storable/ByteString/Internal.hs
@@ -116,10 +116,6 @@ import Control.Monad.Primitive ( unsafeI
 -- from vector:
 import qualified Data.Vector.Storable as VS
 
--- TODO: Temporary:
--- from deepseq:
-import Control.DeepSeq ( NFData )
-
 
 --------------------------------------------------------------------------------
 -- The ByteString type synonym
@@ -129,9 +125,6 @@ import Control.DeepSeq ( NFData )
 -- efficient operations.  A 'ByteString' contains 8-bit characters only.
 type ByteString = VS.Vector Word8
 
--- TODO: Temporary:
-instance NFData (VS.Vector a)
-
 {-
 -- TODO: Probably not a good idea to add these orphaned instances:
 --------------------------------------------------------------------------------
