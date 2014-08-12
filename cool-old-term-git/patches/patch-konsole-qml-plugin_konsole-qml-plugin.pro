$NetBSD: patch-konsole-qml-plugin_konsole-qml-plugin.pro,v 1.1 2014/08/12 21:36:43 thomasklausner Exp $

Do not set relative installation path.

--- konsole-qml-plugin/konsole-qml-plugin.pro.orig	2014-08-12 21:05:24.000000000 +0000
+++ konsole-qml-plugin/konsole-qml-plugin.pro
@@ -15,7 +15,6 @@ TARGET = kdekonsole
 PLUGIN_IMPORT_PATH = org/kde/konsole
 PLUGIN_ASSETS = $$PWD/assets/*
 
-INSTALL_DIR = ../imports
 
 #########################################
 ##              SOURCES
