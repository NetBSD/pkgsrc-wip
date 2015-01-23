$NetBSD: patch-plugins_mathview_xp_AbiMathView.cpp,v 1.1 2015/01/23 14:30:11 nros Exp $
* read config files installed by gtkmathview
--- plugins/mathview/xp/AbiMathView.cpp.orig	2013-04-07 13:53:03.000000000 +0000
+++ plugins/mathview/xp/AbiMathView.cpp
@@ -591,6 +591,19 @@ void GR_MathManager::initialize(void)
 	libCombiningDictDir += "/math/dictionary-combining.xml";
 	libLocalDictDir += "/math/dictionary-local.xml";
 #endif
+	// ... or from gtkmathview it self
+
+	UT_UTF8String gmvConfDir(SYSCONFDIR);
+	UT_UTF8String gmvDictDir(DATADIR);
+	UT_UTF8String gmvCombiningDictDir(DATADIR);
+	UT_UTF8String gmvLocalDictDir(DATADIR);
+
+	gmvConfDir += "/gtkmathview/gtkmathview.conf.xml";
+	gmvDictDir += "/gtkmathview/dictionary.xml";
+	gmvCombiningDictDir += "/gtkmathview/dictionary-combining.xml";
+	gmvLocalDictDir += "/gtkmathview/dictionary-local.xml";
+
+	
 
 	// add the configuration paths
  
@@ -602,6 +615,7 @@ void GR_MathManager::initialize(void)
 		Configuration::addConfigurationPath(bundleConfDir.utf8_str());
 	}
 #endif
+	Configuration::addConfigurationPath( gmvConfDir.utf8_str() );
 	Configuration::addConfigurationPath( libConfDir.utf8_str() );
 	Configuration::addConfigurationPath( userConfDir.utf8_str() );
 
@@ -628,6 +642,10 @@ void GR_MathManager::initialize(void)
 		configuration->add("dictionary/path", bundleLocalDictDir.utf8_str());
 	}
 #endif
+	configuration->add("dictionary/path", gmvDictDir.utf8_str());
+	configuration->add("dictionary/path", gmvCombiningDictDir.utf8_str());
+	configuration->add("dictionary/path", gmvLocalDictDir.utf8_str());
+
 	configuration->add("dictionary/path", libDictDir.utf8_str());
 	configuration->add("dictionary/path", libCombiningDictDir.utf8_str());
 	configuration->add("dictionary/path", libLocalDictDir.utf8_str());
