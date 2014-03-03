$NetBSD: patch-src_scripting_class.h,v 1.1 2014/03/03 08:12:25 nsloss Exp $

Fix for building with clang don't allow instantiation of ASObject template here when included in allclasses.cpp.

--- src/scripting/class.h.orig	2013-03-16 11:19:18.000000000 +0000
+++ src/scripting/class.h
@@ -228,6 +228,7 @@ inline ASObject* Class<Boolean>::coerce(
 	return abstract_b(n);
 }
 
+#if !defined(ALLCLASSES_CPP)
 template<>
 class Class<ASObject>: public Class_base
 {
@@ -318,6 +319,7 @@ public:
 		return ret;
 	}
 };
+#endif
 
 /* InterfaceClass implements interfaces. E.g., if you declare a variable of type IEventDispatcher in AS3,
  * then the type in our code will be InterfaceClass<IEventDispatcher>.
