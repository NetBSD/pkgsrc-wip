$NetBSD$

--- lib/msan/tests/msan_test.cc.orig	2018-02-01 23:46:00.000000000 +0000
+++ lib/msan/tests/msan_test.cc
@@ -65,16 +65,17 @@ int shmdt(const void *);
 #include <sys/ipc.h>
 #include <sys/shm.h>
 
-#if !defined(__FreeBSD__)
-# include <malloc.h>
-# include <sys/sysinfo.h>
-# include <sys/vfs.h>
-# include <mntent.h>
-# include <netinet/ether.h>
-# if defined(__linux__)
-#  include <sys/uio.h>
-# endif
-#else
+#if defined(__NetBSD__)
+# include <signal.h>
+# include <netinet/in.h>
+# include <sys/uio.h>
+# include <sys/mount.h>
+# include <sys/sysctl.h>
+# include <net/if.h>
+# include <net/if_ether.h>
+# include <sched.h>
+# define cpu_set_t cpuset_t
+#elif defined(__FreeBSD__)
 # include <signal.h>
 # include <netinet/in.h>
 # include <pthread_np.h>
@@ -90,6 +91,15 @@ extern "C" {
 // ordinary function, we can declare it here to complete the tests.
 void *mempcpy(void *dest, const void *src, size_t n);
 }
+#else
+# include <malloc.h>
+# include <sys/sysinfo.h>
+# include <sys/vfs.h>
+# include <mntent.h>
+# include <netinet/ether.h>
+# if defined(__linux__)
+#  include <sys/uio.h>
+# endif
 #endif
 
 #if defined(__i386__) || defined(__x86_64__)
@@ -103,8 +113,8 @@ void *mempcpy(void *dest, const void *sr
 # include <immintrin.h>
 #endif
 
-// On FreeBSD procfs is not enabled by default.
-#if defined(__FreeBSD__)
+// On FreeBSD and NetBSD procfs is not enabled by default.
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 # define FILE_TO_READ "/bin/cat"
 # define DIR_TO_READ "/bin"
 # define SUBFILE_TO_READ "cat"
@@ -745,6 +755,7 @@ TEST(MemorySanitizer, fstatat) {
   close(dirfd);
 }
 
+#if !defined(__NetBSD__)
 TEST(MemorySanitizer, statfs) {
   struct statfs st;
   int res = statfs("/", &st);
@@ -753,6 +764,7 @@ TEST(MemorySanitizer, statfs) {
   EXPECT_NOT_POISONED(st.f_bfree);
   EXPECT_NOT_POISONED(st.f_namelen);
 }
+#endif
 
 TEST(MemorySanitizer, statvfs) {
   struct statvfs st;
@@ -829,8 +841,8 @@ TEST(MemorySanitizer, poll) {
   close(pipefd[1]);
 }
 
-// There is no ppoll() on FreeBSD.
-#if !defined (__FreeBSD__)
+// There is no ppoll() on FreeBSD and NetBSD.
+#if !defined (__FreeBSD__) && !defined (__NetBSD__)
 TEST(MemorySanitizer, ppoll) {
   int* pipefd = new int[2];
   int res = pipe(pipefd);
@@ -1168,6 +1180,7 @@ TEST(MemorySanitizer, gethostbyaddr) {
   EXPECT_HOSTENT_NOT_POISONED(he);
 }
 
+#if !defined(__NetBSD__)
 TEST(MemorySanitizer, gethostent_r) {
   char buf[2000];
   struct hostent he;
@@ -1180,7 +1193,9 @@ TEST(MemorySanitizer, gethostent_r) {
   EXPECT_HOSTENT_NOT_POISONED(result);
   EXPECT_NOT_POISONED(err);
 }
+#endif
 
+#if !defined(__NetBSD__)
 TEST(MemorySanitizer, gethostbyname_r) {
   char buf[2000];
   struct hostent he;
@@ -1193,7 +1208,9 @@ TEST(MemorySanitizer, gethostbyname_r) {
   EXPECT_HOSTENT_NOT_POISONED(result);
   EXPECT_NOT_POISONED(err);
 }
+#endif
 
+#if !defined(__NetBSD__)
 TEST(MemorySanitizer, gethostbyname_r_bad_host_name) {
   char buf[2000];
   struct hostent he;
@@ -1203,7 +1220,9 @@ TEST(MemorySanitizer, gethostbyname_r_ba
   ASSERT_EQ((struct hostent *)0, result);
   EXPECT_NOT_POISONED(err);
 }
+#endif
 
+#if !defined(__NetBSD__)
 TEST(MemorySanitizer, gethostbyname_r_erange) {
   char buf[5];
   struct hostent he;
@@ -1213,7 +1232,9 @@ TEST(MemorySanitizer, gethostbyname_r_er
   ASSERT_EQ(ERANGE, errno);
   EXPECT_NOT_POISONED(err);
 }
+#endif
 
+#if !defined(__NetBSD__)
 TEST(MemorySanitizer, gethostbyname2_r) {
   char buf[2000];
   struct hostent he;
@@ -1227,7 +1248,9 @@ TEST(MemorySanitizer, gethostbyname2_r) 
   EXPECT_HOSTENT_NOT_POISONED(result);
   EXPECT_NOT_POISONED(err);
 }
+#endif
 
+#if !defined(__NetBSD__)
 TEST(MemorySanitizer, gethostbyaddr_r) {
   char buf[2000];
   struct hostent he;
@@ -1243,6 +1266,7 @@ TEST(MemorySanitizer, gethostbyaddr_r) {
   EXPECT_HOSTENT_NOT_POISONED(result);
   EXPECT_NOT_POISONED(err);
 }
+#endif
 
 TEST(MemorySanitizer, getsockopt) {
   int sock = socket(AF_UNIX, SOCK_STREAM, 0);
@@ -1269,8 +1293,8 @@ TEST(MemorySanitizer, getcwd_gnu) {
   free(res);
 }
 
-// There's no get_current_dir_name() on FreeBSD.
-#if !defined(__FreeBSD__)
+// There's no get_current_dir_name() on FreeBSD and NetBSD.
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 TEST(MemorySanitizer, get_current_dir_name) {
   char* res = get_current_dir_name();
   ASSERT_TRUE(res != NULL);
@@ -1289,7 +1313,7 @@ TEST(MemorySanitizer, shmctl) {
   EXPECT_NOT_POISONED(ds);
 
   // FreeBSD does not support shmctl(IPC_INFO) and shmctl(SHM_INFO).
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
   struct shminfo si;
   res = shmctl(id, IPC_INFO, (struct shmid_ds *)&si);
   ASSERT_GT(res, -1);
@@ -1337,8 +1361,8 @@ TEST(MemorySanitizer, shmat) {
   ASSERT_GT(res, -1);
 }
 
-// There's no random_r() on FreeBSD.
-#if !defined(__FreeBSD__)
+// There's no random_r() on FreeBSD and NetBSD.
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 TEST(MemorySanitizer, random_r) {
   int32_t x;
   char z[64];
@@ -1419,7 +1443,7 @@ TEST(MemorySanitizer, realpath_null) {
 }
 
 // There's no canonicalize_file_name() on FreeBSD.
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 TEST(MemorySanitizer, canonicalize_file_name) {
   const char* relpath = ".";
   char* res = canonicalize_file_name(relpath);
@@ -1877,8 +1901,8 @@ TEST(MemorySanitizer, modfl) {
   EXPECT_NOT_POISONED(y);
 }
 
-// There's no sincos() on FreeBSD.
-#if !defined(__FreeBSD__)
+// There's no sincos() on FreeBSD and NetBSD.
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 TEST(MemorySanitizer, sincos) {
   double s, c;
   sincos(0.2, &s, &c);
@@ -1887,8 +1911,8 @@ TEST(MemorySanitizer, sincos) {
 }
 #endif
 
-// There's no sincosf() on FreeBSD.
-#if !defined(__FreeBSD__)
+// There's no sincosf() on FreeBSD and NetBSD.
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 TEST(MemorySanitizer, sincosf) {
   float s, c;
   sincosf(0.2, &s, &c);
@@ -1897,8 +1921,8 @@ TEST(MemorySanitizer, sincosf) {
 }
 #endif
 
-// There's no sincosl() on FreeBSD.
-#if !defined(__FreeBSD__)
+// There's no sincosl() on FreeBSD and NetBSD.
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 TEST(MemorySanitizer, sincosl) {
   long double s, c;
   sincosl(0.2, &s, &c);
@@ -1960,8 +1984,8 @@ TEST(MemorySanitizer, lgammaf_r) {
   EXPECT_NOT_POISONED(sgn);
 }
 
-// There's no lgammal_r() on FreeBSD.
-#if !defined(__FreeBSD__)
+// There's no lgammal_r() on FreeBSD and NetBSD.
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 TEST(MemorySanitizer, lgammal_r) {
   int sgn;
   long double res = lgammal_r(1.1, &sgn);
@@ -1970,8 +1994,8 @@ TEST(MemorySanitizer, lgammal_r) {
 }
 #endif
 
-// There's no drand48_r() on FreeBSD.
-#if !defined(__FreeBSD__)
+// There's no drand48_r() on FreeBSD and NetBSD.
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 TEST(MemorySanitizer, drand48_r) {
   struct drand48_data buf;
   srand48_r(0, &buf);
@@ -1981,8 +2005,8 @@ TEST(MemorySanitizer, drand48_r) {
 }
 #endif
 
-// There's no lrand48_r() on FreeBSD.
-#if !defined(__FreeBSD__)
+// There's no lrand48_r() on FreeBSD and NetBSD.
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 TEST(MemorySanitizer, lrand48_r) {
   struct drand48_data buf;
   srand48_r(0, &buf);
@@ -2267,7 +2291,7 @@ TEST(MemorySanitizer, localtime_r) {
   EXPECT_NE(0U, strlen(time.tm_zone));
 }
 
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 /* Creates a temporary file with contents similar to /etc/fstab to be used
    with getmntent{_r}.  */
 class TempFstabFile {
@@ -2305,8 +2329,8 @@ class TempFstabFile {
 };
 #endif
 
-// There's no getmntent() on FreeBSD.
-#if !defined(__FreeBSD__)
+// There's no getmntent() on FreeBSD and NetBSD.
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 TEST(MemorySanitizer, getmntent) {
   TempFstabFile fstabtmp;
   ASSERT_TRUE(fstabtmp.Create());
@@ -2324,8 +2348,8 @@ TEST(MemorySanitizer, getmntent) {
 }
 #endif
 
-// There's no getmntent_r() on FreeBSD.
-#if !defined(__FreeBSD__)
+// There's no getmntent_r() on FreeBSD and NetBSD.
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 TEST(MemorySanitizer, getmntent_r) {
   TempFstabFile fstabtmp;
   ASSERT_TRUE(fstabtmp.Create());
@@ -2345,6 +2369,7 @@ TEST(MemorySanitizer, getmntent_r) {
 }
 #endif
 
+#if !defined(__NetBSD__)
 TEST(MemorySanitizer, ether) {
   const char *asc = "11:22:33:44:55:66";
   struct ether_addr *paddr = ether_aton(asc);
@@ -2363,6 +2388,7 @@ TEST(MemorySanitizer, ether) {
   ASSERT_EQ(s, buf);
   ASSERT_NE(0U, strlen(buf));
 }
+#endif
 
 TEST(MemorySanitizer, mmap) {
   const int size = 4096;
@@ -2383,8 +2409,8 @@ TEST(MemorySanitizer, mmap) {
   }
 }
 
-// There's no fcvt() on FreeBSD.
-#if !defined(__FreeBSD__)
+// There's no fcvt() on FreeBSD and NetBSD.
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 // FIXME: enable and add ecvt.
 // FIXME: check why msandr does nt handle fcvt.
 TEST(MemorySanitizer, fcvt) {
@@ -2402,8 +2428,8 @@ TEST(MemorySanitizer, fcvt) {
 }
 #endif
 
-// There's no fcvt_long() on FreeBSD.
-#if !defined(__FreeBSD__)
+// There's no fcvt_long() on FreeBSD and NetBSD.
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 TEST(MemorySanitizer, fcvt_long) {
   int a, b;
   break_optimization(&a);
@@ -2478,11 +2504,15 @@ void SigactionHandler(int signo, siginfo
   ASSERT_TRUE(si != NULL);
   EXPECT_NOT_POISONED(si->si_errno);
   EXPECT_NOT_POISONED(si->si_pid);
-#if __linux__
-# if defined(__x86_64__)
+#ifdef _UC_MACHINE_PC
+  EXPECT_NOT_POISONED(_UC_MACHINE_PC((ucontext_t*)uc));
+#else
+# if __linux__
+#  if defined(__x86_64__)
   EXPECT_NOT_POISONED(((ucontext_t*)uc)->uc_mcontext.gregs[REG_RIP]);
-# elif defined(__i386__)
+#  elif defined(__i386__)
   EXPECT_NOT_POISONED(((ucontext_t*)uc)->uc_mcontext.gregs[REG_EIP]);
+#  endif
 # endif
 #endif
   ++cnt;
@@ -3012,7 +3042,9 @@ TEST(MemorySanitizer, LongStruct) {
   EXPECT_POISONED(s2.a8);
 }
 
-#ifdef __GLIBC__
+#if defined(__NetBSD__)
+#define MSAN_TEST_PRLIMIT 0
+#elif defined(__GLIBC__)
 #define MSAN_TEST_PRLIMIT __GLIBC_PREREQ(2, 13)
 #else
 #define MSAN_TEST_PRLIMIT 1
@@ -3063,9 +3095,13 @@ TEST(MemorySanitizer, getrusage) {
   EXPECT_NOT_POISONED(usage.ru_nivcsw);
 }
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 static void GetProgramPath(char *buf, size_t sz) {
+#if defined(__FreeBSD__)
   int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+#elif defined(__NetBSD__)
+  int mib[4] = { CTL_KERN, KERN_PROC_ARGS, -1, KERN_PROC_PATHNAME};
+#endif
   int res = sysctl(mib, 4, buf, &sz, NULL, 0);
   ASSERT_EQ(0, res);
 }
@@ -3187,8 +3223,8 @@ TEST(MemorySanitizer, dlopenFailed) {
 
 #endif // MSAN_TEST_DISABLE_DLOPEN
 
-// There's no sched_getaffinity() on FreeBSD.
-#if !defined(__FreeBSD__)
+// There's no sched_getaffinity() on FreeBSD and NetBSD.
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 TEST(MemorySanitizer, sched_getaffinity) {
   cpu_set_t mask;
   int res = sched_getaffinity(getpid(), sizeof(mask), &mask);
@@ -3336,12 +3372,14 @@ TEST(MemorySanitizer, pthread_attr_get) 
     EXPECT_NOT_POISONED(v);
     EXPECT_NOT_POISONED(w);
   }
+#if !defined(__NetBSD__)
   {
     cpu_set_t v;
     res = pthread_attr_getaffinity_np(&attr, sizeof(v), &v);
     ASSERT_EQ(0, res);
     EXPECT_NOT_POISONED(v);
   }
+#endif
   res = pthread_attr_destroy(&attr);
   ASSERT_EQ(0, res);
 }
@@ -3433,8 +3471,8 @@ TEST(MemorySanitizer, posix_memalign) {
   free(p);
 }
 
-// There's no memalign() on FreeBSD.
-#if !defined(__FreeBSD__)
+// There's no memalign() on FreeBSD and NetBSD.
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 TEST(MemorySanitizer, memalign) {
   void *p = memalign(4096, 13);
   EXPECT_EQ(0U, (uintptr_t)p % 4096);
@@ -3449,8 +3487,8 @@ TEST(MemorySanitizer, valloc) {
   free(a);
 }
 
-// There's no pvalloc() on FreeBSD.
-#if !defined(__FreeBSD__)
+// There's no pvalloc() on FreeBSD and NetBSD.
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 TEST(MemorySanitizer, pvalloc) {
   uintptr_t PageSize = GetPageSize();
   void *p = pvalloc(PageSize + 100);
@@ -3507,8 +3545,8 @@ TEST(MemorySanitizer, gethostname) {
   EXPECT_NOT_POISONED(strlen(buf));
 }
 
-// There's no sysinfo() on FreeBSD.
-#if !defined(__FreeBSD__)
+// There's no sysinfo() on FreeBSD and NetBSD.
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 TEST(MemorySanitizer, sysinfo) {
   struct sysinfo info;
   int res = sysinfo(&info);
@@ -3605,8 +3643,8 @@ TEST(MemorySanitizer, getpwent_r) {
   EXPECT_NOT_POISONED(pwdres);
 }
 
-// There's no fgetpwent() on FreeBSD.
-#if !defined(__FreeBSD__)
+// There's no fgetpwent() on FreeBSD and NetBSD.
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 TEST(MemorySanitizer, fgetpwent) {
   FILE *fp = fopen("/etc/passwd", "r");
   struct passwd *p = fgetpwent(fp);
@@ -3629,8 +3667,8 @@ TEST(MemorySanitizer, getgrent) {
   EXPECT_NOT_POISONED(p->gr_gid);
 }
 
-// There's no fgetgrent() on FreeBSD.
-#if !defined(__FreeBSD__)
+// There's no fgetgrent() on FreeBSD and NetBSD.
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 TEST(MemorySanitizer, fgetgrent) {
   FILE *fp = fopen("/etc/group", "r");
   struct group *grp = fgetgrent(fp);
@@ -4392,12 +4430,14 @@ void MemCpyTest() {
   EXPECT_POISONED_O(y[N/2], ox);
   EXPECT_POISONED_O(y[N-1], ox);
   EXPECT_NOT_POISONED(x);
+#if !defined(__NetBSD__)
   void *res = mempcpy(q, x, N * sizeof(T));
   ASSERT_EQ(q + N, res);
   EXPECT_POISONED_O(q[0], ox);
   EXPECT_POISONED_O(q[N/2], ox);
   EXPECT_POISONED_O(q[N-1], ox);
   EXPECT_NOT_POISONED(x);
+#endif
   memmove(z, x, N * sizeof(T));
   EXPECT_POISONED_O(z[0], ox);
   EXPECT_POISONED_O(z[N/2], ox);
