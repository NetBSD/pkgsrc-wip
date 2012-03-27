$NetBSD: patch-UFconfig-UFconfig.mk,v 1.1.1.1 2012/03/27 16:19:22 outpaddling Exp $

# From FreeBSD: Respect the local build environment
--- UFconfig/UFconfig.mk.orig	2011-05-10 20:47:15.000000000 +0000
+++ UFconfig/UFconfig.mk
@@ -33,11 +33,10 @@
 # C compiler and compiler flags:  These will normally not give you optimal
 # performance.  You should select the optimization parameters that are best
 # for your system.  On Linux, use "CFLAGS = -O3 -fexceptions" for example.
-CC = cc
-CFLAGS = -O3 -fexceptions
+CFLAGS = -Wall -g  -I/usr/pkg/include ${PICFLAG}   -fexceptions
 
 # C++ compiler (also uses CFLAGS)
-CPLUSPLUS = g++
+CPLUSPLUS = c++
 
 # ranlib, and ar, for generating libraries
 RANLIB = ranlib
@@ -49,8 +48,7 @@ RM = rm -f
 MV = mv -f
 
 # Fortran compiler (not normally required)
-F77 = f77
-F77FLAGS = -O
+F77FLAGS = -O ${PICFLAG}
 F77LIB =
 
 # C and Fortran libraries
@@ -71,8 +69,8 @@ MEX = mex -O -largeArrayDims -lmwlapack 
 # MAKE = gmake
 
 # For "make install"
-INSTALL_LIB = /usr/local/lib
-INSTALL_INCLUDE = /usr/local/include
+INSTALL_LIB = /usr/pkg/lib
+INSTALL_INCLUDE = /usr/pkg/include
 
 #------------------------------------------------------------------------------
 # BLAS and LAPACK configuration:
@@ -91,8 +89,8 @@ INSTALL_INCLUDE = /usr/local/include
 # naming the BLAS and LAPACK library (*.a or *.so) files.
 
 # This is probably slow ... it might connect to the Standard Reference BLAS:
-BLAS = -lblas -lgfortran
-LAPACK = -llapack
+BLAS =   -L/usr/pkg/lib -Wl,-R/usr/pkg/lib -lblas
+LAPACK =   -L/usr/pkg/lib -Wl,-R/usr/pkg/lib -llapack
 
 # NOTE: this next option for the "Goto BLAS" has nothing to do with a "goto"
 # statement.  Rather, the Goto BLAS is written by Dr. Kazushige Goto.
@@ -132,8 +130,8 @@ XERBLA = 
 # The path is relative to where it is used, in CHOLMOD/Lib, CHOLMOD/MATLAB, etc.
 # You may wish to use an absolute path.  METIS is optional.  Compile
 # CHOLMOD with -DNPARTITION if you do not wish to use METIS.
-METIS_PATH = ../../metis-4.0
-METIS = ../../metis-4.0/libmetis.a
+METIS_PATH = 
+METIS = 
 
 # If you use CHOLMOD_CONFIG = -DNPARTITION then you must use the following
 # options:
@@ -194,7 +192,7 @@ UMFPACK_CONFIG = 
 # -DNSUNPERF	    for Solaris only.  If defined, do not use the Sun
 #			Performance Library
 
-CHOLMOD_CONFIG =
+CHOLMOD_CONFIG = -DNPARTITION
 
 #------------------------------------------------------------------------------
 # SuiteSparseQR configuration:
@@ -208,7 +206,7 @@ CHOLMOD_CONFIG =
 # -DHAVE_TBB        enable the use of Intel's Threading Building Blocks (TBB)
 
 # default, without timing, without TBB:
-SPQR_CONFIG =
+SPQR_CONFIG = -DNPARTITION
 # with timing and TBB:
 # SPQR_CONFIG = -DTIMING -DHAVE_TBB
 # with timing
@@ -237,18 +235,18 @@ RTLIB =
 
 # alternatives:
 # CFLAGS = -g -fexceptions \
-   	-Wall -W -Wshadow -Wmissing-prototypes -Wstrict-prototypes \
-    	-Wredundant-decls -Wnested-externs -Wdisabled-optimization -ansi \
-        -funit-at-a-time
+#   	-Wall -W -Wshadow -Wmissing-prototypes -Wstrict-prototypes \
+#    	-Wredundant-decls -Wnested-externs -Wdisabled-optimization -ansi \
+#       -funit-at-a-time
 # CFLAGS = -O3 -fexceptions \
-   	-Wall -W -Werror -Wshadow -Wmissing-prototypes -Wstrict-prototypes \
-    	-Wredundant-decls -Wnested-externs -Wdisabled-optimization -ansi
+#   	-Wall -W -Werror -Wshadow -Wmissing-prototypes -Wstrict-prototypes \
+#    	-Wredundant-decls -Wnested-externs -Wdisabled-optimization -ansi
 # CFLAGS = -O3 -fexceptions -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE
 # CFLAGS = -O3
 # CFLAGS = -O3 -g -fexceptions
 # CFLAGS = -g -fexceptions \
-   	-Wall -W -Wshadow \
-    	-Wredundant-decls -Wdisabled-optimization -ansi
+#   	-Wall -W -Wshadow \
+#    	-Wredundant-decls -Wdisabled-optimization -ansi
 
 # consider:
 # -fforce-addr -fmove-all-movables -freduce-all-givs -ftsp-ordering
