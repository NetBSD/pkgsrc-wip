$NetBSD$

Support whitespaces in filename
https://github.com/free-electrons/elixir/commit/4845e251862de3e915a1668e7c810072d7adb373#diff-8e6afdf322bc86524af61ffc82e64ca3

--- update.py.orig	2017-05-25 08:56:01.000000000 +0000
+++ update.py
@@ -43,7 +43,7 @@ def updateBlobIDs (tag):
 
     newBlobs = []
     for blob in blobs:
-        hash, filename = blob.split (b' ')
+        hash, filename = blob.split (b' ',maxsplit=1)
         if not db.blob.exists (hash):
             db.blob.put (hash, idx)
             db.hash.put (idx, hash)
@@ -58,7 +58,7 @@ def updateVersions (tag):
     buf = []
 
     for blob in blobs:
-        hash, path = blob.split (b' ')
+        hash, path = blob.split (b' ',maxsplit=1)
         idx = db.blob.get (hash)
         buf.append ((idx, path))
 
