# $NetBSD: buildlink2.mk,v 1.2 2003/09/24 12:33:52 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libhydrogen.
#
# This file was created automatically using createbuildlink 2.7.
#

.if !defined(LIBHYDROGEN_BUILDLINK2_MK)
LIBHYDROGEN_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libhydrogen
BUILDLINK_DEPENDS.libhydrogen?=		libhydrogen>=0.8.0
BUILDLINK_PKGSRCDIR.libhydrogen?=		../../wip/libhydrogen

EVAL_PREFIX+=	BUILDLINK_PREFIX.libhydrogen=libhydrogen
BUILDLINK_PREFIX.libhydrogen_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libhydrogen+=	include/hydrogen/*.h
BUILDLINK_FILES.libhydrogen+=	lib/libhydrogen.*

.include "../../audio/libaudiofile/buildlink2.mk"

BUILDLINK_TARGETS+=	libhydrogen-buildlink

libhydrogen-buildlink: _BUILDLINK_USE

.endif	# LIBHYDROGEN_BUILDLINK2_MK
