$NetBSD$

Don't build a .app just because we're on macOS.

--- cmake/Install.cmake.orig	2021-03-31 09:24:50.000000000 +0000
+++ cmake/Install.cmake
@@ -3,7 +3,7 @@
 # It will be included by ./src/CMakeLists.txt
 ################################################
 
-if(MAC)
+if(MACAPP)
 	set(DEFAULT_FILE_DESTINATION ${PROJECT_NAME}.app/Contents/Resources)
 	set(TRANSLATION_DESTINATION ${DEFAULT_FILE_DESTINATION}/translations)
 else()
@@ -46,7 +46,7 @@ set(DEPENDENCY_CHECK "
 
 
 # qt qml plugins (fixup_bundle needs to know this to fetch their dependencies)
-if((WIN32 OR MAC) AND TARGET ${Qt}::Qml)
+if((WIN32 OR MACAPP) AND TARGET ${Qt}::Qml)
 	set(modules QtQuick QtQuick.2 QtQml QtGraphicalEffects Qt)
 	if(WIN32)
 		list(APPEND modules QtWinExtras)
@@ -113,7 +113,7 @@ if(WIN32)
 
 
 
-elseif(MAC)
+elseif(MACAPP)
 	set(MACOS_BUNDLE_MACOS_DIR ${DEFAULT_FILE_DESTINATION}/../MacOS)
 	set(MACOS_BUNDLE_PLUGINS_DIR ${DEFAULT_FILE_DESTINATION}/../PlugIns)
 	set(MACOS_BUNDLE_FRAMEWORKS_DIR ${DEFAULT_FILE_DESTINATION}/../Frameworks)
@@ -274,7 +274,7 @@ endif()
 
 
 
-if(LINUX OR WIN32 OR MAC)
+if(LINUX OR WIN32 OR MACAPP)
 	option(SELFPACKER "Compress executable with self packer like UPX")
 	if(SELFPACKER)
 		find_package(SelfPackers)
@@ -315,7 +315,7 @@ if(SIGNTOOL_CMD)
 
 	configure_file(${CMAKE_DIR}/SignFiles.cmake.in ${CMAKE_BINARY_DIR}/SignFiles.cmake @ONLY)
 
-	if(MAC)
+	if(MACAPP)
 		option(OSX_TIMESTAMP "Timestamp the application bundle" ON)
 
 		install(CODE
