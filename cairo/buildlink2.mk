# $NetBSD: buildlink2.mk,v 1.2 2004/01/19 21:08:46 marc Exp $
#

.if !defined(CAIRO_BUILDLINK2_MK)
CAIRO_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			cairo
BUILDLINK_DEPENDS.cairo?=		cairo>=0.1.17
BUILDLINK_PKGSRCDIR.cairo?=		../../wip/cairo

EVAL_PREFIX+=	BUILDLINK_PREFIX.cairo=cairo
BUILDLINK_PREFIX.cairo_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.cairo+=	include/cairo-features.h
BUILDLINK_FILES.cairo+=	include/cairo.h
BUILDLINK_FILES.cairo+=	lib/libcairo.*

BUILDLINK_DEPENDS.freetype2=  freetype2>=2.1.5

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../wip/libpixman/buildlink2.mk"

BUILDLINK_TARGETS+=	cairo-buildlink

cairo-buildlink: _BUILDLINK_USE

.endif	# CAIRO_BUILDLINK2_MK
