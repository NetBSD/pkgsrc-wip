$NetBSD$

--- lib/asan/scripts/asan_symbolize.py.orig	2017-07-03 15:33:06.000000000 +0000
+++ lib/asan/scripts/asan_symbolize.py
@@ -280,7 +280,7 @@ def BreakpadSymbolizerFactory(binary):
 def SystemSymbolizerFactory(system, addr, binary, arch):
   if system == 'Darwin':
     return DarwinSymbolizer(addr, binary, arch)
-  elif system == 'Linux' or system == 'FreeBSD':
+  elif system == 'Linux' or system == 'FreeBSD' or system == 'NetBSD':
     return Addr2LineSymbolizer(binary)
 
 
@@ -370,7 +370,7 @@ class SymbolizationLoop(object):
       self.binary_name_filter = binary_name_filter
       self.dsym_hint_producer = dsym_hint_producer
       self.system = os.uname()[0]
-      if self.system not in ['Linux', 'Darwin', 'FreeBSD']:
+      if self.system not in ['Linux', 'Darwin', 'FreeBSD', 'NetBSD']:
         raise Exception('Unknown system')
       self.llvm_symbolizers = {}
       self.last_llvm_symbolizer = None
