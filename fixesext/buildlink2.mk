# $NetBSD: buildlink2.mk,v 1.3 2004/01/31 22:23:35 minskim Exp $
#
# This Makefile fragment is included by packages that use fixesext.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(FIXESEXT_BUILDLINK2_MK)
FIXESEXT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			fixesext
BUILDLINK_DEPENDS.fixesext?=		fixesext>=2.0
BUILDLINK_PKGSRCDIR.fixesext?=		../../wip/fixesext

EVAL_PREFIX+=	BUILDLINK_PREFIX.fixesext=fixesext
BUILDLINK_PREFIX.fixesext_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.fixesext+=	include/X11/extensions/xfixesproto.h
BUILDLINK_FILES.fixesext+=	include/X11/extensions/xfixeswire.h

.include "../../wip/xextensions/buildlink2.mk"

BUILDLINK_TARGETS+=	fixesext-buildlink

fixesext-buildlink: _BUILDLINK_USE

.endif	# FIXESEXT_BUILDLINK2_MK
