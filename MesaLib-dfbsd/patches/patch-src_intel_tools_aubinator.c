$NetBSD$

From FreeBSD ports graphics/libGL mesa 13.0.5

# We don't have MAP_NORESERVE so use MAP_NOSYNC | MAP_NOCORE and
# hope for the best (this alloc is too big but it's only a test)

--- src/intel/tools/aubinator.c.orig	2017-02-13 11:55:49.000000000 +0000
+++ src/intel/tools/aubinator.c
@@ -1298,8 +1298,14 @@ int main(int argc, char *argv[])
 
    /* mmap a terabyte for our gtt space. */
    gtt_size = 1ull << 40;
+/* MAP_NORESERVE removed in FreeBSD 11 and never was implemented before */
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+   gtt = mmap(NULL, gtt_size, PROT_READ | PROT_WRITE,
+              MAP_PRIVATE | MAP_ANONYMOUS |  MAP_NOSYNC | MAP_NOCORE, -1, 0);
+#else
    gtt = mmap(NULL, gtt_size, PROT_READ | PROT_WRITE,
               MAP_PRIVATE | MAP_ANONYMOUS |  MAP_NORESERVE, -1, 0);
+#endif
    if (gtt == MAP_FAILED) {
       fprintf(stderr, "failed to alloc gtt space: %s\n", strerror(errno));
       exit(EXIT_FAILURE);
