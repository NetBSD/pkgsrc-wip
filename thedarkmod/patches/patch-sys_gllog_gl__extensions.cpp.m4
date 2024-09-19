$NetBSD$

--- sys/gllog/gl_extensions.cpp.m4.orig	2019-02-02 17:51:38.000000000 +0000
+++ sys/gllog/gl_extensions.cpp.m4
@@ -46,16 +46,12 @@ GLExtension_t GLimp_ExtensionPointer( co
 	}
 	#endif
 	GLExtension_t ret;
-	#if defined(__linux__)    
 	// for some reason glXGetProcAddressARB doesn't work on RH9?
 	ret = qglXGetProcAddressARB((const GLubyte *) name);
 	if ( !ret ) {
 		common->Printf("glXGetProcAddressARB failed: \"%s\"\n", name);
 		return StubFunction;
 	}
-	#else
-    #error Need OS define
-	#endif
 	return ret;
 #endif
 }
