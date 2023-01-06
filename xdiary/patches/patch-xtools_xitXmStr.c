$NetBSD$

Provide a definition of const.

--- xtools/xitXmStr.c.orig	1995-02-18 14:11:37.000000000 +0000
+++ xtools/xitXmStr.c
@@ -56,10 +56,6 @@ static char SCCSID[] = "@(#) Module: xit
 --  Macro definitions
 ----------------------------------------------------------------------------*/
 
-#ifndef _POSIX_SOURCE
-#  define  const
-#endif
-
 
 /*----------------------------------------------------------------------------
 --  Type declarations
