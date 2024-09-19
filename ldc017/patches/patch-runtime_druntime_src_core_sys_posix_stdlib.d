$NetBSD$

--- runtime/druntime/src/core/sys/posix/stdlib.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/stdlib.d
@@ -95,6 +95,10 @@ else version( DragonFlyBSD )
 {
     int posix_memalign(void**, size_t, size_t);
 }
+else version( NetBSD )
+{
+    int posix_memalign(void**, size_t, size_t);
+}
 else version( Solaris )
 {
     int posix_memalign(void**, size_t, size_t);
@@ -174,6 +178,10 @@ else version( DragonFlyBSD )
 {
     int rand_r(uint*);
 }
+else version( NetBSD )
+{
+    int rand_r(uint*);
+}
 else version( Solaris )
 {
     int rand_r(uint*);
@@ -361,6 +369,47 @@ else version( DragonFlyBSD )
 {
     //WNOHANG     (defined in core.sys.posix.sys.wait)
     //WUNTRACED   (defined in core.sys.posix.sys.wait)
+    //WEXITSTATUS (defined in core.sys.posix.sys.wait)
+    //WIFEXITED   (defined in core.sys.posix.sys.wait)
+    //WIFSIGNALED (defined in core.sys.posix.sys.wait)
+    //WIFSTOPPED  (defined in core.sys.posix.sys.wait)
+    //WSTOPSIG    (defined in core.sys.posix.sys.wait)
+    //WTERMSIG    (defined in core.sys.posix.sys.wait)
+
+    c_long a64l(in char*);
+    double drand48();
+    //char*  ecvt(double, int, int *, int *); // LEGACY
+    double erand48(ref ushort[3]);
+    //char*  fcvt(double, int, int *, int *); // LEGACY
+    //char*  gcvt(double, int, char*); // LEGACY
+    int    getsubopt(char**, in char**, char**);
+    int    grantpt(int);
+    char*  initstate(uint, char*, size_t);
+    c_long jrand48(ref ushort[3]);
+    char*  l64a(c_long);
+    void   lcong48(ref ushort[7]);
+    c_long lrand48();
+    char*  mktemp(char*); // LEGACY
+    int    mkstemp(char*);
+    char*  mkdtemp(char*); // Defined in IEEE 1003.1, 2008 Edition
+    c_long mrand48();
+    c_long nrand48(ref ushort[3]);
+    int    posix_openpt(int);
+    char*  ptsname(int);
+    int    putenv(char*);
+    c_long random();
+    char*  realpath(in char*, char*);
+    ushort *seed48(ref ushort[3]);
+    void   setkey(in char*);
+    char*  setstate(in char*);
+    void   srand48(c_long);
+    void   srandom(uint);
+    int    unlockpt(int);
+}
+else version( NetBSD )
+{
+    //WNOHANG     (defined in core.sys.posix.sys.wait)
+    //WUNTRACED   (defined in core.sys.posix.sys.wait)
     //WEXITSTATUS (defined in core.sys.posix.sys.wait)
     //WIFEXITED   (defined in core.sys.posix.sys.wait)
     //WIFSIGNALED (defined in core.sys.posix.sys.wait)
