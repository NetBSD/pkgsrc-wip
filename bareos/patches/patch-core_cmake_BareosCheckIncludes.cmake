$NetBSD$

	Fix header file checks for NetBSD

--- core/cmake/BareosCheckIncludes.cmake.orig	2018-12-20 08:51:51.000000000 +0000
+++ core/cmake/BareosCheckIncludes.cmake
@@ -56,7 +56,7 @@ CHECK_INCLUDE_FILES(sys/dl.h HAVE_SYS_DL
 CHECK_INCLUDE_FILES(sys/ea.h HAVE_SYS_EA_H)
 CHECK_INCLUDE_FILES("sys/types.h;sys/extattr.h" HAVE_SYS_EXTATTR_H)
 CHECK_INCLUDE_FILES(sys/ioctl.h HAVE_SYS_IOCTL_H)
-CHECK_INCLUDE_FILES(sys/mtio.h HAVE_SYS_MTIO_H)
+CHECK_INCLUDE_FILES("sys/types.h;sys/mtio.h" HAVE_SYS_MTIO_H)
 CHECK_INCLUDE_FILES(sys/ndir.h HAVE_SYS_NDIR_H)
 CHECK_INCLUDE_FILES(sys/nvpair.h HAVE_SYS_NVPAIR_H)
 CHECK_INCLUDE_FILES(sys/select.h HAVE_SYS_SELECT_H)
@@ -135,7 +135,7 @@ CHECK_INCLUDE_FILES(term.h HAVE_TERM_H)
 CHECK_INCLUDE_FILES("sys/types.h;sys/scsi/impl/uscsi.h" HAVE_SYS_SCSI_IMPL_USCSI_H)
 CHECK_INCLUDE_FILES("stdio.h;camlib.h" HAVE_CAMLIB_H)
 CHECK_INCLUDE_FILES(cam/scsi/scsi_message.h HAVE_CAM_SCSI_SCSI_MESSAGE_H)
-CHECK_INCLUDE_FILES(dev/scsipi/scsipi_all.h HAVE_DEV_SCSIPI_SCSIPI_ALL_H)
+CHECK_INCLUDE_FILES("sys/types.h;dev/scsipi/scsipi_all.h" HAVE_DEV_SCSIPI_SCSIPI_ALL_H)
 
 CHECK_INCLUDE_FILES(scsi/uscsi_all.h HAVE_USCSI_ALL_H)
 CHECK_INCLUDE_FILES(scsi/uscsi_all.h HAVE_SCSI_USCSI_ALL_H)
