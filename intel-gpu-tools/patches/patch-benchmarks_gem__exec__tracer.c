$NetBSD$

--- benchmarks/gem_exec_tracer.c.orig	2015-08-17 16:38:30.000000000 +0000
+++ benchmarks/gem_exec_tracer.c
@@ -214,6 +214,17 @@ ioctl(int fd, unsigned long request, ...
 	if (ret)
 		return ret;
 
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
 	if (_IOC_TYPE(request) != DRM_IOCTL_BASE)
 		return 0;
 
