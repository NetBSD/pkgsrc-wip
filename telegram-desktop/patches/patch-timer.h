$NetBSD$

--- Telegram/lib_base/base/timer.h.orig	2020-02-16 20:39:14.706242585 +0000
+++ Telegram/lib_base/base/timer.h
@@ -8,6 +8,7 @@
 
 #include <QtCore/QObject>
 #include <QtCore/QThread>
+#include "base/base_pch.h"
 #include "base/flat_map.h"
 
 #include <crl/crl_time.h>
