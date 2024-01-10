$NetBSD$

Moved stat64 & friends to #define and added #if section to select

--- diskio-unix.cc.orig	2022-04-14 23:17:12.000000000 +0000
+++ diskio-unix.cc
@@ -41,6 +41,26 @@ using namespace std;
 #define off64_t off_t
 #endif
 
+#if defined(WIN32)
+#define STAT64_STRUCT __stat64
+#define STAT64_FUNCTION _stat64
+#define FSTAT64_FUNCTION _fstat64
+#define LSEEK64_FUNCTION _lseek64
+#define OFFSET_TYPE _off64_t
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined (__APPLE__)
+#define STAT64_STRUCT stat
+#define STAT64_FUNCTION stat
+#define FSTAT64_FUNCTION fstat
+#define LSEEK64_FUNCTION lseek
+#define OFFSET_TYPE off_t
+#else
+#define STAT64_STRUCT stat64
+#define STAT64_FUNCTION stat64
+#define FSTAT64_FUNCTION fstat64
+#define LSEEK64_FUNCTION lseek64
+#define OFFSET_TYPE off64_t
+#endif 
+
 // Returns the official "real" name for a shortened version of same.
 // Trivial here; more important in Windows
 void DiskIO::MakeRealName(void) {
@@ -52,7 +72,7 @@ void DiskIO::MakeRealName(void) {
 // work.
 int DiskIO::OpenForRead(void) {
    int shouldOpen = 1;
-   struct stat64 st;
+   struct STAT64_STRUCT st;
 
    if (isOpen) { // file is already open
       if (openForWrite) {
@@ -65,7 +85,7 @@ int DiskIO::OpenForRead(void) {
    if (shouldOpen) {
       fd = open(realFilename.c_str(), O_RDONLY);
       if (fd == -1) {
-         cerr << "Problem opening " << realFilename << " for reading! Error is " << errno << ".\n";
+         cerr << "Problem opening " << realFilename << " for reading! Error is " << errno << " (" << strerror(errno) << ")\n";
          if (errno == EACCES) // User is probably not running as root
             cerr << "You must run this program as root or use sudo!\n";
          if (errno == ENOENT)
@@ -78,11 +98,11 @@ int DiskIO::OpenForRead(void) {
       } else {
          isOpen = 0;
          openForWrite = 0;
-         if (fstat64(fd, &st) == 0) {
+         if (FSTAT64_FUNCTION(fd, &st) == 0) {
             if (S_ISDIR(st.st_mode))
                cerr << "The specified path is a directory!\n";
 #if !(defined(__FreeBSD__) || defined(__FreeBSD_kernel__)) \
-                       && !defined(__APPLE__)
+                       && !defined(__APPLE__) && !defined(__NetBSD__)
             else if (S_ISCHR(st.st_mode))
                cerr << "The specified path is a character device!\n";
 #endif
@@ -92,7 +112,7 @@ int DiskIO::OpenForRead(void) {
                cerr << "The specified path is a socket!\n";
             else
                isOpen = 1;
-         } // if (fstat64()...)
+         } // if (FSTAT64_FUNCTION()...)
 #if defined(__linux__) && !defined(EFI)
          if (isOpen && realFilename.substr(0,4) == "/dev") {
             ostringstream modelNameFilename;
@@ -120,7 +140,7 @@ int DiskIO::OpenForWrite(void) {
 
    // try to open the device; may fail....
    fd = open(realFilename.c_str(), O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__)
    // MacOS X requires a shared lock under some circumstances....
    if (fd < 0) {
       cerr << "Warning: Devices opened with shared lock will not have their\npartition table automatically reloaded!\n";
@@ -170,7 +190,7 @@ int DiskIO::GetBlockSize(void) {
       if (err == 0)
           blockSize = minfo.dki_lbsize;
 #endif
-#if defined (__FreeBSD__) || defined (__FreeBSD_kernel__)
+#if defined (__FreeBSD__) || defined (__FreeBSD_kernel__) || defined(__NetBSD__)
       err = ioctl(fd, DIOCGSECTORSIZE, &blockSize);
 #endif
 #ifdef __linux__
@@ -286,6 +306,16 @@ int DiskIO::DiskSync(void) {
            << "You should reboot or remove the drive.\n";
       platformFound++;
 #endif
+#if defined (__NetBSD__)
+      sleep(2);
+      if (ioctl(fd, DIOCCACHESYNC, &i) == -1)
+          cout << "Error " << errno << " synchronizing cache (" << strerror(errno) << ")\n";
+      else
+          cout << "successfully synchronized\n";
+      cout << "Warning: The kernel may continue to use old or deleted wedges.\n"
+           << "You should reboot or remove the drive.\n";
+      platformFound++;
+#endif
 #ifdef __linux__
       sleep(1); // Theoretically unnecessary, but ioctl() fails sometimes if omitted....
       fsync(fd);
@@ -311,7 +341,7 @@ int DiskIO::DiskSync(void) {
 // Note that seeking beyond the end of the file is NOT detected as a failure!
 int DiskIO::Seek(uint64_t sector) {
    int retval = 1;
-   off64_t seekTo, sought;
+   OFFSET_TYPE seekTo, sought;
 
    // If disk isn't open, try to open it....
    if (!isOpen) {
@@ -320,7 +350,7 @@ int DiskIO::Seek(uint64_t sector) {
 
    if (isOpen) {
       seekTo = sector * (uint64_t) GetBlockSize();
-      sought = lseek64(fd, seekTo, SEEK_SET);
+      sought = LSEEK64_FUNCTION(fd, seekTo, SEEK_SET);
       if (sought != seekTo) {
          retval = 0;
       } // if
@@ -428,8 +458,8 @@ int DiskIO::Write(void* buffer, int numB
 // return correct values for disk image files.
 uint64_t DiskIO::DiskSize(int *err) {
    uint64_t sectors = 0; // size in sectors
-   off64_t bytes = 0; // size in bytes
-   struct stat64 st;
+   OFFSET_TYPE bytes = 0; // size in bytes
+   struct STAT64_STRUCT st;
    int platformFound = 0;
 #ifdef __sun__
    struct dk_minfo minfo;
@@ -456,7 +486,7 @@ uint64_t DiskIO::DiskSize(int *err) {
           sectors = minfo.dki_capacity;
       platformFound++;
 #endif
-#if defined (__FreeBSD__) || defined (__FreeBSD_kernel__)
+#if defined (__FreeBSD__) || defined (__FreeBSD_kernel__) || defined(__NetBSD__)
       *err = ioctl(fd, DIOCGMEDIASIZE, &bytes);
       long long b = GetBlockSize();
       sectors = bytes / b;
@@ -488,7 +518,7 @@ uint64_t DiskIO::DiskSize(int *err) {
       // file (a QEMU image, dd backup, or what have you) and see what
       // fstat() gives us....
       if ((sectors == 0) || (*err == -1)) {
-         if (fstat64(fd, &st) == 0) {
+         if (FSTAT64_FUNCTION(fd, &st) == 0) {
             bytes = st.st_size;
             if ((bytes % UINT64_C(512)) != 0)
                cerr << "Warning: File size is not a multiple of 512 bytes!"
