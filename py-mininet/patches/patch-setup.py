$NetBSD$

--- setup.py.orig	2020-09-24 00:55:15.000000000 +0000
+++ setup.py
@@ -10,7 +10,7 @@ import sys
 sys.path.append( '.' )
 from mininet.net import VERSION
 
-scripts = [ join( 'bin', filename ) for filename in [ 'mn' ] ]
+scripts = [ join( 'bin', filename ) for filename in [ 'mn'+sys.version[0:3] ]]
 
 modname = distname = 'mininet'
 
