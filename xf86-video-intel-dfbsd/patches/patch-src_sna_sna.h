$NetBSD: patch-src_sna_sna.h,v 1.1 2016/12/07 21:59:54 wiz Exp $

Upstream patches for xorg-server-1.19.

Patches from NetBSD xsrc xf86-video-intel-2014

--- src/sna/sna.h.orig	2019-03-01 18:22:07.000000000 +0000
+++ src/sna/sna.h
@@ -1336,11 +1336,18 @@ char *sna_cpu_features_to_string(unsigne
 int sna_acpi_open(void);
 void sna_acpi_init(struct sna *sna);
 void _sna_acpi_wakeup(struct sna *sna);
+#if defined(HANDLER_XSRC_NETBSD)
+static inline void sna_acpi_wakeup(struct sna *sna)
+{
+	_sna_acpi_wakeup(sna);
+}
+#else
 static inline void sna_acpi_wakeup(struct sna *sna, void *read_mask)
 {
 	if (sna->acpi.fd >= 0 && FD_ISSET(sna->acpi.fd, (fd_set*)read_mask))
 		_sna_acpi_wakeup(sna);
 }
+#endif
 void sna_acpi_fini(struct sna *sna);
 
 void sna_threads_init(void);
