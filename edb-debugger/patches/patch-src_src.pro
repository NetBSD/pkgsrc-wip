$NetBSD$

--- src/src.pro.orig	2014-01-14 21:10:03.000000000 +0000
+++ src/src.pro
@@ -176,21 +176,16 @@ unix {
 	VPATH       += $$LEVEL/include/os/unix edisassm
 	INCLUDEPATH += $$LEVEL/include/os/unix edisassm
 
-	linux-* {
-		VPATH       += $$LEVEL/include/os/unix/linux
-		INCLUDEPATH += $$LEVEL/include/os/unix/linux
-	}
-
-	openbsd-* {
-		VPATH       += $$LEVEL/include/os/unix/openbsd
-		INCLUDEPATH += $$LEVEL/include/os/unix/openbsd /usr/local/include
-	}
-
 	freebsd-* {
 		VPATH       += $$LEVEL/include/os/unix/freebsd
 		INCLUDEPATH += $$LEVEL/include/os/unix/freebsd
 	}
 
+	linux-* {
+		VPATH       += $$LEVEL/include/os/unix/linux
+		INCLUDEPATH += $$LEVEL/include/os/unix/linux
+	}
+
 	macx-* {
 		VPATH       += $$LEVEL/include/os/unix/osx
 		INCLUDEPATH += $$LEVEL/include/os/unix/osx /opt/local/include
@@ -201,6 +196,16 @@ unix {
 		INCLUDEPATH += arch/x86_64 $$LEVEL/include/arch/x86_64
 	}
 
+	netbsd-* {
+		VPATH       += $$LEVEL/include/os/unix/netbsd
+		INCLUDEPATH += $$LEVEL/include/os/unix/netbsd
+	}
+
+	openbsd-* {
+		VPATH       += $$LEVEL/include/os/unix/openbsd
+		INCLUDEPATH += $$LEVEL/include/os/unix/openbsd /usr/local/include
+	}
+
 	!macx:contains(QMAKE_HOST.arch, x86_64) {
 		VPATH       += arch/x86_64 $$LEVEL/include/arch/x86_64
 		INCLUDEPATH += arch/x86_64 $$LEVEL/include/arch/x86_64
@@ -221,6 +226,6 @@ unix {
 	linux-g++*   : QMAKE_LFLAGS += -rdynamic $$(LDFLAGS)
 	macx-clang*  : QMAKE_LFLAGS += -rdynamic $$(LDFLAGS)
 	macx-g++*    : QMAKE_LFLAGS += -rdynamic $$(LDFLAGS)
+	netbsd-g++*  : QMAKE_LFLAGS += -lkvm -Wl,--export-dynamic $$(LDFLAGS)
 	openbsd-g++* : QMAKE_LFLAGS += -lkvm -Wl,--export-dynamic $$(LDFLAGS)
 }
-
