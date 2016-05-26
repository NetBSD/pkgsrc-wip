$NetBSD$

--- src/corelib/io/io.pri.orig	2016-05-20 00:28:32.000000000 +0000
+++ src/corelib/io/io.pri
@@ -147,7 +147,6 @@ win32 {
             SOURCES += io/qsettings_mac.cpp
             OBJECTIVE_SOURCES += io/qurl_mac.mm
         }
-        freebsd: LIBS_PRIVATE += -lutil         # qlockfile_unix.cpp requires this
         mac {
             osx {
                 OBJECTIVE_SOURCES += io/qfilesystemwatcher_fsevents.mm
