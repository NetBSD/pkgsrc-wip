$NetBSD: patch-src_plugins_plugins.pro,v 1.1 2014/12/04 15:51:26 nros Exp $
* Don't install testplugin even in debug mode (fixes PLIST)
--- src/plugins/plugins.pro.orig	2014-12-04 16:14:11.000000000 +0000
+++ src/plugins/plugins.pro
@@ -30,7 +30,7 @@ outOfDirPlugins = $$(QUPZILLA_PLUGINS_SR
 !equals(outOfDirPlugins, ""): addSubdir($$(QUPZILLA_PLUGINS_SRCDIR))
 
 # TestPlugin only in debug build
-!CONFIG(debug, debug|release): disablePlugin(TestPlugin)
+disablePlugin(TestPlugin)
 
 # KWalletPasswords only with KDE_INTEGRATION and KWallet framework
 !contains(DEFINES, KDE_INTEGRATION): disablePlugin(KWalletPasswords)
