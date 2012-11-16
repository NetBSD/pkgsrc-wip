$NetBSD: patch-qcppdialogimpl.cpp,v 1.1 2012/11/16 22:25:07 helgoman Exp $

#Make DEVICES available depending of the installing system 
--- qcppdialogimpl.cpp.orig	2009-06-25 20:10:49.000000000 +0000
+++ qcppdialogimpl.cpp
@@ -16,7 +16,7 @@
 
 */
 
-#include "qcppdialogimpl.h"
+#include <qcppdialogimpl.h>
 
 #include <qcombobox.h>
 #include <qpushbutton.h>
@@ -351,12 +351,12 @@ void QCPPDialogImpl::readSettings()
    QStringList devices=settings.value("/cutecom/AllDevices").toStringList();
    if (!entryFound)
    {
-      devices<<"/dev/ttyS0"<<"/dev/ttyS1"<<"/dev/ttyS2"<<"/dev/ttyS3";
+      devices<<DEVLIST;
    }
 
    m_deviceCb->insertItems(0, devices);
 
-   int indexOfCurrentDevice = devices.indexOf(settings.value("/cutecom/CurrentDevice", "/dev/ttyS0").toString());
+   int indexOfCurrentDevice = devices.indexOf(settings.value("/cutecom/CurrentDevice", DEFAULT_DEV).toString());
    // fprintf(stderr, "currentDEev: -%s - index: %d\n", settings.value("/cutecom/CurrentDevice", "/dev/ttyS0").toString().toLatin1().constData(), indexOfCurrentDevice);
    if (indexOfCurrentDevice!=-1)
    {
