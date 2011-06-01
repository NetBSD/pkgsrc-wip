$NetBSD: patch-docs_administration.rst,v 1.1.1.1 2011/06/01 03:51:46 schnoebe Exp $

edit in the macro for configuration directory replacement.

--- docs/administration.rst.orig	2011-05-08 16:36:35.000000000 +0000
+++ docs/administration.rst
@@ -21,13 +21,13 @@ and is a good starting point for new con
 
 :file:`bravo.ini` should live in one of three locations:
 
-1. /etc/bravo
+1. @PKG_SYSCONFDIR@/bravo
 2. ~/.bravo
 3. The working directory
 
 All three locations will be checked, in that order, and more-recently-loaded
 configurations will override configurations in previous directories. For
-sanity purposes, it is highly encouraged to either use :file:`/etc/bravo`
+sanity purposes, it is highly encouraged to either use :file:`@PKG_SYSCONFDIR@/bravo`
 if running as root, or :file:`~/.bravo` if running as a normal user.
 
 The configuration file is divided up into **sections**. Each section starts
