$NetBSD: patch-tdefunc.h,v 1.1 2013/01/03 13:06:34 othyro Exp $

key_name is already defined in curses.h.

--- tdefunc.h.orig	2006-02-19 04:50:20.000000000 +0000
+++ tdefunc.h
@@ -320,7 +320,6 @@ int  save_strokes( TDE_WIN * );
 void write_macro( FILE *, MACRO *, long );
 void write_pseudomacro( FILE *, TREE * );
 void write_twokeymacro( FILE *, TREE * );
-char *key_name( long, char * );
 int  clear_macros( TDE_WIN * );
 void delete_pseudomacro( TREE * );
 void delete_twokeymacro( TREE * );
