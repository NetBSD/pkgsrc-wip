# $NetBSD: buildlink2.mk,v 1.2 2004/02/19 17:49:24 thomasklausner Exp $
#
# This Makefile fragment is included by packages that use gift.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(GIFT_BUILDLINK2_MK)
GIFT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gift
BUILDLINK_DEPENDS.gift?=		gift>=0.11.3
BUILDLINK_PKGSRCDIR.gift?=		../../wip/gift

EVAL_PREFIX+=	BUILDLINK_PREFIX.gift=gift
BUILDLINK_PREFIX.gift_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gift+=	include/libgift/*.h
BUILDLINK_FILES.gift+=	lib/libgift.*
BUILDLINK_FILES.gift+=	lib/libgiftproto.*
BUILDLINK_FILES.gift+=	lib/pkgconfig/libgift.pc

.include "../../audio/libvorbis/buildlink2.mk"

BUILDLINK_TARGETS+=	gift-buildlink

gift-buildlink: _BUILDLINK_USE

.endif	# GIFT_BUILDLINK2_MK
