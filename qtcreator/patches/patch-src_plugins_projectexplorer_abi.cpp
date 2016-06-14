$NetBSD$

Cherry-pick upstream patch by Ralf Nolden:
https://codereview.qt-project.org/#/c/162330/2/src/plugins/projectexplorer/abi.cpp

--- src/plugins/projectexplorer/abi.cpp.orig	2016-06-06 13:26:59.000000000 +0000
+++ src/plugins/projectexplorer/abi.cpp
@@ -199,12 +199,20 @@ static QList<Abi> abiOf(const QByteArray
         Abi::OSFlavor flavor = Abi::GenericUnixFlavor;
         // http://www.sco.com/developers/gabi/latest/ch4.eheader.html#elfid
         switch (osAbi) {
-        case 2: // NetBSD:
+#if defined(Q_OS_NETBSD)
+        case 0: // NetBSD: ELFOSABI_NETBSD  2, however, NetBSD uses 0
             os = Abi::BsdOS;
             flavor = Abi::NetBsdFlavor;
             break;
+#elif defined(Q_OS_OPENBSD)
+	case 0: // OpenBSD: ELFOSABI_OPENBSD 12, however, OpenBSD uses 0
+		os = Abi::BsdOS;
+		flavor = Abi::OpenBsdFlavor;
+		break;
+#else
+	case 0: // no extra info available: Default to Linux
+#endif
         case 3: // Linux:
-        case 0: // no extra info available: Default to Linux:
         case 97: // ARM, also linux most of the time.
             os = Abi::LinuxOS;
             flavor = Abi::GenericLinuxFlavor;
@@ -217,9 +225,6 @@ static QList<Abi> abiOf(const QByteArray
             os = Abi::BsdOS;
             flavor = Abi::FreeBsdFlavor;
             break;
-        case 12: // OpenBSD:
-            os = Abi::BsdOS;
-            flavor = Abi::OpenBsdFlavor;
         }
 
         switch (machine) {
