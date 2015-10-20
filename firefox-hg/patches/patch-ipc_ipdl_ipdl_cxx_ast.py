$NetBSD: patch-ipc_ipdl_ipdl_cxx_ast.py,v 1.1 2014/09/29 10:46:25 thomasklausner Exp $

Part of https://bugzilla.mozilla.org/show_bug.cgi?id=1026499:
Make sure storage provided for attributes is properly aligned
in the generated C++ code.

--- ipc/ipdl/ipdl/cxx/ast.py.orig	2015-10-20 08:24:26.000000000 +0000
+++ ipc/ipdl/ipdl/cxx/ast.py
@@ -340,12 +340,13 @@ Type.VOIDPTR = Type('void', ptr=1)
 Type.AUTO = Type('auto')
 
 class TypeArray(Node):
-    def __init__(self, basetype, nmemb):
-        '''the type |basetype DECLNAME[nmemb]|.  |nmemb| is an Expr'''
+    def __init__(self, basetype, nmemb, alignType):
+        '''the type |basetype DECLNAME[nmemb]|.  |nmemb| is an Expr, |alignType| is a type'''
         self.basetype = basetype
         self.nmemb = nmemb
+        self.alignType = alignType
     def __deepcopy__(self, memo):
-        return TypeArray(deepcopy(self.basetype, memo), nmemb)
+        return TypeArray(deepcopy(self.basetype, memo), nmemb, alignType)
 
 class TypeEnum(Node):
     def __init__(self, name=None):
