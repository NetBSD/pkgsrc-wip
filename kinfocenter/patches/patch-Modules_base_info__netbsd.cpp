$NetBSD$

<kio/global.h> not used (and not found)
Try PCIUTILS

--- Modules/base/info_netbsd.cpp.orig	2020-05-05 14:39:33.000000000 +0000
+++ Modules/base/info_netbsd.cpp
@@ -25,13 +25,16 @@
 #include <stdlib.h>	/* for malloc(3) */
 #include <fstab.h>
 
+#ifdef HAVE_PCIUTILS
+#include "kpci.h"
+#endif //HAVE_PCIUTILS
 #include <QFile>
 #include <QStringList>
 #include <QTextStream>
 #include <QTreeWidgetItemIterator>
 
 #include <QDebug>
-#include <kio/global.h> /* for KIO::convertSize() */
+/* #include <kio/global.h> /* for KIO::convertSize() */
 
 typedef struct {
 	int string;
@@ -133,6 +136,14 @@ bool GetInfo_DMA(QTreeWidget*) {
 }
 
 bool GetInfo_PCI(QTreeWidget* tree) {
+        int num;
+
+#ifdef HAVE_PCIUTILS
+        if ( (num = GetInfo_PCIUtils(tree))) {
+                return num;
+        }
+        
+#endif //HAVE_PCIUTILS
 	if (!GetDmesgInfo(tree, "at pci", NULL)) {
 		QStringList list;
 		list << i18n("No PCI devices found.");
