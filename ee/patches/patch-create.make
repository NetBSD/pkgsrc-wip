$NetBSD$

Link against ncurses.

--- create.make.orig	2002-09-23 04:18:30.000000000 +0000
+++ create.make
@@ -267,7 +267,7 @@ echo "all :	$TARGET" >> make.local
 cat  >> make.local << EOF
 
 curses :	ee.c
-	cc ee.c -o ee \$(CFLAGS) -lcurses 
+	cc ee.c -o ee \$(CFLAGS) `pkg-config --libs ncurses`
 
 ee :	ee.o new_curse.o
 	cc -o ee ee.o new_curse.o \$(CFLAGS) 
