# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/11/27 01:30:55 xtraeme Exp $
#
# This Makefile fragment is included by packages that use damageext.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(DAMAGEEXT_BUILDLINK2_MK)
DAMAGEEXT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			damageext
BUILDLINK_DEPENDS.damageext?=		damageext>=1.0
BUILDLINK_PKGSRCDIR.damageext?=		../../wip/damageext

EVAL_PREFIX+=	BUILDLINK_PREFIX.damageext=damageext
BUILDLINK_PREFIX.damageext_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.damageext+=	include/X11/extensions/damageproto.h
BUILDLINK_FILES.damageext+=	include/X11/extensions/damagewire.h


BUILDLINK_TARGETS+=	damageext-buildlink

damageext-buildlink: _BUILDLINK_USE

.endif	# DAMAGEEXT_BUILDLINK2_MK
