$NetBSD$

--- platforms/unix/vm-display-X11/acinclude.m4.orig	2022-06-02 14:10:44.000000000 +0000
+++ platforms/unix/vm-display-X11/acinclude.m4
@@ -45,16 +45,16 @@ if test "$have_x" = "yes"; then
     INCLUDES="${INCLUDES} -I${x_includes}"
     X_INCLUDES="-I${x_includes}"
   fi
-  AC_SEARCH_LIBS([XOpenDisplay],[X11], [
+  PKG_CHECK_MODULES([x11], [x11], [
     AC_DEFINE([USE_X11], [1], [Use X11])
     AC_DEFINE_UNQUOTED([VM_X11DIR], "${x_libraries}", [X11 libraries])
-    AC_SEARCH_LIBS([XShmAttach],[Xext], [
+    PKG_CHECK_MODULES([xext], [xext], [
       AC_DEFINE([HAVE_LIBXEXT], [1], [Have Xext library])
     ])
     if test "$have_gl" = ""; then have_gl="no"; fi
     if test "$have_gl" = "yes"; then
       AC_CHECK_HEADERS([GL/gl.h gl/gl.h gl.h], [
-        AC_SEARCH_LIBS([glIsEnabled],[GL], [
+        PKG_CHECK_MODULES([gl], [gl], [
           have_gl=yes 
           AC_DEFINE([USE_X11_GLX], [1], [Use X11 GLX])
           break
@@ -88,9 +88,10 @@ X_INCLUDES=${INCLUDES}
 AC_SUBST(X_INCLUDES)
 
 LIBS=${VMLIBS}
-CFLAGS=${VMCFLAGS}
+CFLAGS="${VMCFLAGS} ${x11_CFLAGS} ${xext_CFLAGS} ${gl_CFLAGS}"
 CPPFLAGS=${VMCPPFLAGS}
 INCLUDES=${VMINCLUDES}
+LDFLAGS="${LDFLAGS} ${x11_LIBS} ${xext_LIBS} ${gl_LIBS}"
 
 AC_SUBST(VM_DISPX11_OBJS, $vm_dispx11_objs)
 AC_SUBST(VM_DISPX11_BITBLT_FLAGS, $vm_dispx11_bitblt_flags)
