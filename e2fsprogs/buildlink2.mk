# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/04 18:15:40 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use e2fsprogs.
#
# This file was created automatically using createbuildlink 2.9.
#

.if !defined(E2FSPROGS_BUILDLINK2_MK)
E2FSPROGS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			e2fsprogs
BUILDLINK_DEPENDS.e2fsprogs?=		e2fsprogs>=1.34
BUILDLINK_PKGSRCDIR.e2fsprogs?=		../../sysutils/e2fsprogs

EVAL_PREFIX+=	BUILDLINK_PREFIX.e2fsprogs=e2fsprogs
BUILDLINK_PREFIX.e2fsprogs_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.e2fsprogs+=	include/blkid/*.h
BUILDLINK_FILES.e2fsprogs+=	include/e2p/e2p.h
BUILDLINK_FILES.e2fsprogs+=	include/et/com_err.h
BUILDLINK_FILES.e2fsprogs+=	include/ext2fs/*.h
BUILDLINK_FILES.e2fsprogs+=	include/ss/*.h
BUILDLINK_FILES.e2fsprogs+=	include/uuid/*.h
.if ${OPSYS} == "Linux"
BUILDLINK_FILES.e2fsprogs+=	lib/evms/libe2fsim.1.2.1.*
.endif
BUILDLINK_FILES.e2fsprogs+=	lib/libblkid.*
BUILDLINK_FILES.e2fsprogs+=	lib/libcom_err.*
BUILDLINK_FILES.e2fsprogs+=	lib/libe2p.*
BUILDLINK_FILES.e2fsprogs+=	lib/libext2fs.*
BUILDLINK_FILES.e2fsprogs+=	lib/libss.*
BUILDLINK_FILES.e2fsprogs+=	lib/libuuid.*

.include "../../devel/gettext-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	e2fsprogs-buildlink

e2fsprogs-buildlink: _BUILDLINK_USE

.endif	# E2FSPROGS_BUILDLINK2_MK
