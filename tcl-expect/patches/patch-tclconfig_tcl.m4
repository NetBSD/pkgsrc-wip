$NetBSD$

#       tclconfig/tcl.m4
#       add support for svr5

# Emailed Upstream September 2019

--- tclconfig/tcl.m4.orig	2018-02-04 06:55:43.000000000 +0000
+++ tclconfig/tcl.m4	2022-04-30 09:18:53.837696001 +0000
@@ -1817,16 +1817,42 @@
 	    AS_IF([test "$GCC" = yes], [
 		SHLIB_CFLAGS="-fPIC -melf"
 		LDFLAGS="$LDFLAGS -melf -Wl,-Bexport"
+	        SHLIB_LD="gcc"
 	    ], [
 	       SHLIB_CFLAGS="-Kpic -belf"
 	       LDFLAGS="$LDFLAGS -belf -Wl,-Bexport"
-	    ])
 	    SHLIB_LD="ld -G"
+	    ])
 	    SHLIB_LD_LIBS=""
 	    SHLIB_SUFFIX=".so"
 	    CC_SEARCH_FLAGS=""
 	    LD_SEARCH_FLAGS=""
 	    ;;
+       UnixWare-5*|SCO_SV-5*)
+            # -Kthread will define _REENTRANT
+            AS_IF([test "$GCC" = yes], [
+                SHLIB_CFLAGS="-fPIC"
+                SHLIB_LD='${CC} ${CFLAGS} -shared'
+            ], [
+                SHLIB_CFLAGS="-KPIC"
+                SHLIB_LD="${CC} ${CFLAGS} -G -z text"
+            ])
+            SHLIB_LD_LIBS="-lsocket -lnsl"
+            SHLIB_SUFFIX=".so"
+            CC_SEARCH_FLAGS=""
+            LD_SEARCH_FLAGS=""
+            AS_IF([test "${TCL_THREADS}" = "1"], [
+                LIBS=`echo $LIBS | sed s/-lpthread//`
+            AS_IF([test "$GCC" = yes], [
+                # The -lpthread needs to go in the CFLAGS, not LIBS
+                CFLAGS="$CFLAGS -pthread"
+                LDFLAGS="$LDFLAGS -pthread"
+              ], [
+                  CFLAGS="$CFLAGS -Kpthread"
+                  LDFLAGS="$LDFLAGS -Kpthread"
+              ])
+           ])
+           ;;
 	SunOS-5.[[0-6]])
 	    # Careful to not let 5.10+ fall into this case
 
@@ -1968,9 +1994,10 @@
 	    BSD/OS*) ;;
 	    CYGWIN_*) ;;
 	    IRIX*) ;;
-	    NetBSD-*|FreeBSD-*|OpenBSD-*) ;;
+	    NetBSD-*|FreeBSD-*|OpenBSD-*|DragonFly-*|MirBSD-*) ;;
 	    Darwin-*) ;;
 	    SCO_SV-3.2*) ;;
+	    UnixWare-5*|SCO_SV-3.5*) ;;
 	    windows) ;;
 	    *) SHLIB_CFLAGS="-fPIC" ;;
 	esac])
@@ -3212,6 +3239,9 @@
     # substituted. (@@@ Might not be necessary anymore)
     #--------------------------------------------------------------------
 
+    PVNODOTS=`echo ${PACKAGE_VERSION} | tr -d .`
+    SHARED_LIB_SUFFIX=${PVNODOTS}.so
+    UNSHARED_LIB_SUFFIX=${PVNODOTS}.a
     if test "${TEA_PLATFORM}" = "windows" ; then
 	if test "${SHARED_BUILD}" = "1" ; then
 	    # We force the unresolved linking of symbols that are really in
