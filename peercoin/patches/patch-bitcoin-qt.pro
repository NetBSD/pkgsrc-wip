$NetBSD$

Use pkgsrc databases/db4.

--- bitcoin-qt.pro.orig	2015-07-27 20:55:24.000000000 +0000
+++ bitcoin-qt.pro
@@ -289,22 +289,26 @@ isEmpty(BOOST_THREAD_LIB_SUFFIX) {
 
 isEmpty(BDB_LIB_PATH) {
     macx:BDB_LIB_PATH = /opt/local/lib/db48
+    unix:BDB_LIB_PATH = $$PREFIX/lib
 }
 
 isEmpty(BDB_LIB_SUFFIX) {
-    macx:BDB_LIB_SUFFIX = -4.8
+    macx|unix:BDB_LIB_SUFFIX = -4.8
 }
 
 isEmpty(BDB_INCLUDE_PATH) {
     macx:BDB_INCLUDE_PATH = /opt/local/include/db48
+    unix:BDB_INCLUDE_PATH = $$PREFIX/include/db4
 }
 
 isEmpty(BOOST_LIB_PATH) {
     macx:BOOST_LIB_PATH = /opt/local/lib
+    unix:BOOST_LIB_PATH = $$PREFIX/lib
 }
 
 isEmpty(BOOST_INCLUDE_PATH) {
     macx:BOOST_INCLUDE_PATH = /opt/local/include
+    unix:BOOST_INCLUDE_PATH = $$PREFIX/include/boost
 }
 
 windows:LIBS += -lws2_32 -lshlwapi
@@ -337,7 +341,7 @@ macx:TARGET = "PPcoin-Qt"
 # Set libraries and includes at end, to use platform-defined defaults if not overridden
 INCLUDEPATH += $$BOOST_INCLUDE_PATH $$BDB_INCLUDE_PATH $$OPENSSL_INCLUDE_PATH $$QRENCODE_INCLUDE_PATH
 LIBS += $$join(BOOST_LIB_PATH,,-L,) $$join(BDB_LIB_PATH,,-L,) $$join(OPENSSL_LIB_PATH,,-L,) $$join(QRENCODE_LIB_PATH,,-L,)
-LIBS += -lssl -lcrypto -ldb_cxx$$BDB_LIB_SUFFIX
+LIBS += -lssl -lcrypto -ldb4_cxx$$BDB_LIB_SUFFIX
 # -lgdi32 has to happen after -lcrypto (see  #681)
 windows:LIBS += -lole32 -luuid -lgdi32
 LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX
