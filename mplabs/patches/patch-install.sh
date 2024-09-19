$NetBSD: patch-install.sh,v 1.1 2012/09/16 00:02:18 jihbed Exp $

--- install.sh.orig	2012-09-14 11:40:17.000000000 +0100
+++ install.sh	2012-09-14 11:49:08.000000000 +0100
@@ -42,7 +42,7 @@
 
 # Set the compilation flags depending on the input options
 # GNU gfortran
-export CMPR1=gfortran
+export CMPR1=g95
 export CMPR2=mpif90
 export CFLAGS1="-c -Wall -ffree-form -O3"
 export CFLAGS2="-c -Wall -ffree-form -O3"
