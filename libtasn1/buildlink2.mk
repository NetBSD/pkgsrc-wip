# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/05/13 02:31:47 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libtasn1.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(LIBTASN1_BUILDLINK2_MK)
LIBTASN1_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libtasn1
BUILDLINK_DEPENDS.libtasn1?=		libtasn1>=0.1.2
BUILDLINK_PKGSRCDIR.libtasn1?=		../../wip/libtasn1

EVAL_PREFIX+=	BUILDLINK_PREFIX.libtasn1=libtasn1
BUILDLINK_PREFIX.libtasn1_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libtasn1+=	include/libtasn1.h
BUILDLINK_FILES.libtasn1+=	lib/libtasn1.*

BUILDLINK_TARGETS+=	libtasn1-buildlink

libtasn1-buildlink: _BUILDLINK_USE

.endif	# LIBTASN1_BUILDLINK2_MK
