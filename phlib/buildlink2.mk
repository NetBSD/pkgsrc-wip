# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/01/05 18:44:24 poppnk Exp $
#
# This Makefile fragment is included by packages that use phlib.
#
# This file was created automatically using createbuildlink 2.9.
#

.if !defined(PHLIB_BUILDLINK2_MK)
PHLIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			phlib
BUILDLINK_DEPENDS.phlib?=		phlib>=1.20
BUILDLINK_PKGSRCDIR.phlib?=		../../wip/phlib

EVAL_PREFIX+=	BUILDLINK_PREFIX.phlib=phlib
BUILDLINK_PREFIX.phlib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.phlib+=	include/phlib/xl_assert.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_base64_decode.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_base64_encode.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_config.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_datachain.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_date.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_dbeng.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_dir.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_file.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_ipaddr.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_linklst.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_logging.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_malloc.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_memdb.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_memlst.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_memory.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_mmap.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_readrc.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_socket.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_string.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_types.h
BUILDLINK_FILES.phlib+=	include/phlib/xl_ufile.h
BUILDLINK_FILES.phlib+=	lib/libpxtra.*
BUILDLINK_FILES.phlib+=	lib/libpxtra.a.${PKGVERSION}
BUILDLINK_FILES.phlib+=	lib/libpxtra.a.1

BUILDLINK_TARGETS+=	phlib-buildlink

phlib-buildlink: _BUILDLINK_USE

.endif	# PHLIB_BUILDLINK2_MK
