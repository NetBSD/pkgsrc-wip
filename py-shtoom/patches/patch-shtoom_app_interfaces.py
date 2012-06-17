$NetBSD: patch-shtoom_app_interfaces.py,v 1.1 2012/06/17 12:56:23 spzeidler Exp $

--- ./shtoom/app/interfaces.py.orig	2004-01-16 16:37:36.000000000 +0000
+++ ./shtoom/app/interfaces.py
@@ -1,7 +1,7 @@
 # Copyright (C) 2004 Anthony Baxter
 # This file is necessary to make this directory a package
 
-from twisted.python.components import Interface
+from zope.interface import Interface
 
 class ApplicationSIPInterface(Interface):
     """This interface describes the interface to the Application that 
