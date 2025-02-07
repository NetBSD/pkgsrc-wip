$NetBSD$

--- sdk/include/mega/posix/megafs.h.orig	2025-01-24 13:56:57.000000000 +0100
+++ sdk/include/mega/posix/megafs.h
@@ -192,8 +192,7 @@ private:
 
 };
 
-#ifdef __linux__
-
+#if defined(__linux__)
 #define FSACCESS_CLASS LinuxFileSystemAccess
 
 class LinuxFileSystemAccess
@@ -260,6 +259,18 @@ private:
 
 #endif // ENABLE_SYNC
 
+#elif  defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+#define FSACCESS_CLASS BSDFileSystemAccess
+
+class BSDFileSystemAccess
+  : public PosixFileSystemAccess
+{
+public:
+    ~BSDFileSystemAccess();
+    void addevents(Waiter* waiter, int flags) override;
+    int checkevents(Waiter* waiter) override;
+};
+
 #endif // __linux__
 
 } // namespace
