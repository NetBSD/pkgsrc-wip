# $NetBSD: buildlink2.mk,v 1.4 2004/02/22 21:16:08 mpasternak Exp $
#
# This Makefile fragment is included by packages that use libtlen.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBTLEN_BUILDLINK2_MK)
LIBTLEN_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libtlen
BUILDLINK_DEPENDS.libtlen?=		libtlen>=20040212
BUILDLINK_PKGSRCDIR.libtlen?=		../../wip/libtlen

EVAL_PREFIX+=	BUILDLINK_PREFIX.libtlen=libtlen
BUILDLINK_PREFIX.libtlen_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libtlen+=	include/libtlen
BUILDLINK_FILES.libtlen+=	include/libtlen/*.h
BUILDLINK_FILES.libtlen+=	lib/libtlen.*

BUILDLINK_TARGETS+=	libtlen-buildlink

libtlen-buildlink: _BUILDLINK_USE

.endif	# LIBTLEN_BUILDLINK2_MK
