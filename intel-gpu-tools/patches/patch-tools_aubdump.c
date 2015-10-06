$NetBSD$

--- tools/aubdump.c.orig	2015-09-08 17:01:19.000000000 +0000
+++ tools/aubdump.c
@@ -418,6 +418,17 @@ ioctl(int fd, unsigned long request, ...
 	argp = va_arg(args, void *);
 	va_end(args);
 
+#ifndef _IOC_TYPE
+/*
+ * this is from Linux but I suppose NetBSD drm uses the same ioctl encoding?
+ */
+#define _IOC_TYPEBITS 8
+#define _IOC_NRBITS 8
+#define _IOC_NRSHIFT 0
+#define _IOC_TYPESHIFT (_IOC_NRSHIFT+_IOC_NRBITS)
+#define _IOC_TYPEMASK ((1 << _IOC_TYPEBITS)-1)
+#define _IOC_TYPE(nr) (((nr) >> _IOC_TYPESHIFT) & _IOC_TYPEMASK)
+#endif
 	if (_IOC_TYPE(request) == DRM_IOCTL_BASE &&
 	    drm_fd != fd && fstat(fd, &buf) == 0 &&
 	    (buf.st_mode & S_IFMT) == S_IFCHR && major(buf.st_rdev) == DRM_MAJOR) {
