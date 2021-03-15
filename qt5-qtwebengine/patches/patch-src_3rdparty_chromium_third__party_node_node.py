$NetBSD$

--- src/3rdparty/chromium/third_party/node/node.py.orig	2020-07-09 10:26:29.252112529 +0000
+++ src/3rdparty/chromium/third_party/node/node.py
@@ -13,6 +13,7 @@ def GetBinaryPath():
   return os_path.join(os_path.dirname(__file__), *{
     'Darwin': ('mac', 'node-darwin-x64', 'bin', 'node'),
     'Linux': ('linux', 'node-linux-x64', 'bin', 'node'),
+    'NetBSD': ('netbsd', 'node', 'bin', 'node'),
     'Windows': ('win', 'node.exe'),
   }[platform.system()])
 
