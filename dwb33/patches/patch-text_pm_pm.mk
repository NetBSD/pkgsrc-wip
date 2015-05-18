$NetBSD: patch-text_pm_pm.mk,v 1.1 2015/05/18 11:14:47 n-t-roff Exp $

Force C++ compiler for .c files.

--- text/pm/pm.mk.orig	2015-05-17 18:28:51.000000000 +0200
+++ text/pm/pm.mk	2015-05-17 22:27:15.000000000 +0200
@@ -3,7 +3,6 @@
 #
 
 #CC=CC
-CC=$(CXX)
 
 MAKE=/bin/make
 MAKEFILE=pm.mk
@@ -66,8 +65,11 @@
 	    -e "s:TMACDIR:$(TMACDIR):" \
 	tmac.spe.sr >tmac.spe
 
+.c.o:
+	$(CXX) $(CFLAGS) -c $<
+
 pm : $(OFILES)
-	$(CC) $(CFLAGS) -o pm $(OFILES) -lm
+	$(CXX) $(CFLAGS) -o pm $(OFILES) -lm
 
 misc.o : misc.h
 slug.o : slug.h misc.h
