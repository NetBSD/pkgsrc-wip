# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/11/27 02:15:04 xtraeme Exp $
#
# This Makefile fragment is included by packages that use renderext.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(RENDEREXT_BUILDLINK2_MK)
RENDEREXT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			renderext
BUILDLINK_DEPENDS.renderext?=		renderext>=0.8
BUILDLINK_PKGSRCDIR.renderext?=		../../wip/renderext

EVAL_PREFIX+=	BUILDLINK_PREFIX.renderext=renderext
BUILDLINK_PREFIX.renderext_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.renderext+=	include/X11/extensions/render.h
BUILDLINK_FILES.renderext+=	include/X11/extensions/renderproto.h


BUILDLINK_TARGETS+=	renderext-buildlink

renderext-buildlink: _BUILDLINK_USE

.endif	# RENDEREXT_BUILDLINK2_MK
