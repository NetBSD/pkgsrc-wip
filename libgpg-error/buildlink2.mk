# $NetBSD: buildlink2.mk,v 1.4 2004/02/25 13:29:25 johnrshannon Exp $
#
# This Makefile fragment is included by packages that use libgpg-error.
#
# This file was created automatically using createbuildlink-3.1.
#

.if !defined(LIBGPG_ERROR_BUILDLINK2_MK)
LIBGPG_ERROR_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgpg-error
BUILDLINK_DEPENDS.libgpg-error?=		libgpg-error>=0.6
BUILDLINK_PKGSRCDIR.libgpg-error?=		../../wip/libgpg-error

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgpg-error=libgpg-error
BUILDLINK_PREFIX.libgpg-error_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libgpg-error+=	include/gpg-error.h
BUILDLINK_FILES.libgpg-error+=	lib/libgpg-error.*

BUILDLINK_TARGETS+=	libgpg-error-buildlink

libgpg-error-buildlink: _BUILDLINK_USE

.endif	# LIBGPG_ERROR_BUILDLINK2_MK
