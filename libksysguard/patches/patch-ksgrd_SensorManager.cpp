$NetBSD$

--- ksgrd/SensorManager.cpp.orig	2016-04-19 11:13:53.000000000 +0000
+++ ksgrd/SensorManager.cpp
@@ -85,6 +85,7 @@ void SensorManager::retranslate()
   mDict.insert( QStringLiteral( "wired" ), i18n( "Wired Memory" ) );
   mDict.insert( QStringLiteral( "execpages" ), i18n( "Exec Pages" ) );
   mDict.insert( QStringLiteral( "filepages" ), i18n( "File Pages" ) );
+  mDict.insert( QStringLiteral( "anonpages" ), i18n( "Anon Pages" ) );
 
   /* Processes */
   mDict.insert( QStringLiteral( "processes" ), i18n( "Processes" ) );
