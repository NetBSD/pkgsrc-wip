$NetBSD$

--- src/VBox/GuestHost/OpenGL/util/dll.c.orig	2016-03-04 19:29:23.000000000 +0000
+++ src/VBox/GuestHost/OpenGL/util/dll.c
@@ -14,7 +14,7 @@
 #include <string.h>
 #endif
 
-#if defined(IRIX) || defined(IRIX64) || defined(Linux) || defined(FreeBSD) || defined(AIX) || defined(DARWIN) || defined(SunOS) || defined(OSF1)
+#if defined(IRIX) || defined(IRIX64) || defined(Linux) || defined(FreeBSD) || defined(AIX) || defined(DARWIN) || defined(SunOS) || defined(OSF1) || defined(__NetBSD__)
 #include <dlfcn.h>
 #endif
 
@@ -269,7 +269,7 @@ CRDLL *crDLLOpen( const char *dllname, i
 		dll_err = "Unknown DLL type";
 		break;
 	};
-#elif defined(IRIX) || defined(IRIX64) || defined(Linux) || defined(FreeBSD) || defined(AIX) || defined(SunOS) || defined(OSF1)
+#elif defined(IRIX) || defined(IRIX64) || defined(Linux) || defined(FreeBSD) || defined(AIX) || defined(SunOS) || defined(OSF1) || defined(__NetBSD__)
 	if (resolveGlobal)
 		dll->hinstLib = dlopen( dllname, RTLD_LAZY | RTLD_GLOBAL );
 	else
@@ -322,7 +322,7 @@ CRDLLFunc crDLLGetNoError( CRDLL *dll, c
 
 	return (CRDLLFunc) NSAddressOfSymbol( nssym );
 
-#elif defined(IRIX) || defined(IRIX64) || defined(Linux) || defined(FreeBSD) || defined(AIX) || defined(SunOS) || defined(OSF1)
+#elif defined(IRIX) || defined(IRIX64) || defined(Linux) || defined(FreeBSD) || defined(AIX) || defined(SunOS) || defined(OSF1) || defined(__NetBSD__)
 	return (CRDLLFunc) dlsym( dll->hinstLib, symname );
 #else
 #error CR DLL ARCHITETECTURE
@@ -366,7 +366,7 @@ void crDLLClose( CRDLL *dll )
 		NSUnLinkModule( (NSModule) dll->hinstLib, 0L );
 		break;
 	}
-#elif defined(IRIX) || defined(IRIX64) || defined(Linux) || defined(FreeBSD) || defined(AIX) || defined(SunOS) || defined(OSF1)
+#elif defined(IRIX) || defined(IRIX64) || defined(Linux) || defined(FreeBSD) || defined(AIX) || defined(SunOS) || defined(OSF1) || defined(__NetBSD__)
 	/*
 	 * Unloading Nvidia's libGL will crash VirtualBox later during shutdown.
 	 * Therefore we will skip unloading it. It will be unloaded later anway
