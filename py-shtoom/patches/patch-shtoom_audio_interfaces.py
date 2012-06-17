$NetBSD: patch-shtoom_audio_interfaces.py,v 1.1 2012/06/17 12:56:23 spzeidler Exp $

--- ./shtoom/audio/interfaces.py.orig	2004-01-10 14:54:53.000000000 +0000
+++ ./shtoom/audio/interfaces.py
@@ -1,4 +1,4 @@
-from twisted.python.components import Interface
+from zope.interface import Interface
 
 
 class IAudio(Interface):
