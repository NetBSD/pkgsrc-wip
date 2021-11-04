$NetBSD$

--- platforms/unix/vm-display-X11/acinclude.m4.orig	2018-10-19 04:12:21.000000000 +0000
+++ platforms/unix/vm-display-X11/acinclude.m4
@@ -45,18 +45,19 @@ if test "$have_x" = "yes"; then
     INCLUDES="${INCLUDES} -I${x_includes}"
     X_INCLUDES="-I${x_includes}"
   fi
-  AC_SEARCH_LIBS([XOpenDisplay],[X11], [
+  PKG_CHECK_MODULES([x11], [x11], [
     AC_DEFINE([USE_X11], [1], [Use X11])
     AC_DEFINE_UNQUOTED([VM_X11DIR], "${x_libraries}", [X11 libraries])
-    AC_SEARCH_LIBS([XShmAttach],[Xext])
+    PKG_CHECK_MODULES([xext], [xext])
+
     if test "$have_gl" = ""; then have_gl="no"; fi
     if test "$have_gl" = "yes"; then
-        AC_CHECK_HEADERS([GL/gl.h gl/gl.h gl.h], [
-          have_gl=yes
-          AC_DEFINE([USE_X11_GLX], [1], [Use X11 GLX])
-          AC_SEARCH_LIBS([glIsEnabled],[GL])
-          break
-        ])
+      PKG_CHECK_MODULES([gl], [gl], [
+        AC_CHECK_HEADERS([GL/gl.h gl/gl.h gl.h])
+        have_gl=yes
+        AC_DEFINE([USE_X11_GLX], [1], [Use X11 GLX])
+        break
+      ])
     else
         AC_DEFINE([USE_X11_GLX], [0], [Use X11 GLX])
     fi
@@ -77,9 +78,10 @@ X_INCLUDES=${INCLUDES}
 AC_SUBST(X_INCLUDES)
 
 LIBS=${VMLIBS}
-CFLAGS=${VMCFLAGS}
+CFLAGS="${VMCFLAGS} ${x11_CFLAGS} ${xext_CFLAGS} ${gl_CFLAGS}"
 CPPFLAGS=${VMCPPFLAGS}
 INCLUDES=${VMINCLUDES}
+LDFLAGS="${LDFLAGS} ${x11_LIBS} ${xext_LIBS} ${gl_LIBS}"
 
 AC_SUBST(VM_DISPX11_OBJS, $vm_dispx11_objs)
 AC_SUBST(VM_DISPX11_BITBLT_FLAGS, $vm_dispx11_bitblt_flags)
