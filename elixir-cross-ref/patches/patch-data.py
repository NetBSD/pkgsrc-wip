$NetBSD$

Support whitespaces in filename
https://github.com/free-electrons/elixir/commit/4845e251862de3e915a1668e7c810072d7adb373#diff-8e6afdf322bc86524af61ffc82e64ca3

--- data.py.orig	2017-05-25 08:56:01.000000000 +0000
+++ data.py
@@ -51,7 +51,7 @@ class DefList:
         self.data = data
 
     def iter (self, dummy=False):
-        for p in self.data.split (b','):
+        for p in self.data.split (b',',maxsplit=1):
             p = re.search (b'(\d*)(\w)(\d*)', p)
             id, type, line = p.groups()
             id = int (id)
