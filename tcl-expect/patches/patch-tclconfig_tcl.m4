$NetBSD$

On OpenServer 5, when compiling with gcc, also use gcc to link,
because the system ld is not GNU ld.

Add support for Unixware and SCO_SV-5, and add them to the list of
systems needing -fPIC.

Sent upstream by email September 2019.

--- tclconfig/tcl.m4.orig	2018-02-04 06:55:43.000000000 +0000
+++ tclconfig/tcl.m4	2022-06-07 08:37:43.412809932 -0600
@@ -1814,19 +1814,50 @@
 	    LD_SEARCH_FLAGS=""
 	    ;;
 	SCO_SV-3.2*)
+	    # fix SCO OpenServer 5 linking with gcc
+	    # gcc is use to link, there is no gnu ld.
+	    # native compiler uses ld which comes with OS
+
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
+	    # Add UnixWare 
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
 
@@ -1971,6 +2003,7 @@
 	    NetBSD-*|FreeBSD-*|OpenBSD-*) ;;
 	    Darwin-*) ;;
 	    SCO_SV-3.2*) ;;
+	    UnixWare-5*|SCO_SV-3.5*) ;;
 	    windows) ;;
 	    *) SHLIB_CFLAGS="-fPIC" ;;
 	esac])
