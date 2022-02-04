$NetBSD$

Add missing conditional for X11.

--- dlls/winex11.drv/x11drv_main.c.orig	2022-01-18 20:52:35.000000000 +0000
+++ dlls/winex11.drv/x11drv_main.c
@@ -569,6 +569,7 @@ static void init_visuals( Display *displ
 static BOOL process_attach(void)
 {
     Display *display;
+#ifdef SONAME_LIBX11
     void *libx11 = dlopen( SONAME_LIBX11, RTLD_NOW|RTLD_GLOBAL );
 
     if (!libx11)
@@ -578,6 +579,7 @@ static BOOL process_attach(void)
     }
     pXGetEventData = dlsym( libx11, "XGetEventData" );
     pXFreeEventData = dlsym( libx11, "XFreeEventData" );
+#endif
 #ifdef SONAME_LIBXEXT
     dlopen( SONAME_LIBXEXT, RTLD_NOW|RTLD_GLOBAL );
 #endif
