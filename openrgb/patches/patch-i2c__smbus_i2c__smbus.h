$NetBSD$

--- i2c_smbus/i2c_smbus.h.orig	2024-10-23 13:05:19.802903692 +0000
+++ i2c_smbus/i2c_smbus.h
@@ -12,6 +12,7 @@
 #define I2C_SMBUS_H
 
 #include <atomic>
+#include <stdarg.h>
 #include <thread>
 #include <condition_variable>
 #include <mutex>
