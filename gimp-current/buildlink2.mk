# $NetBSD: buildlink2.mk,v 1.2 2003/06/10 13:50:23 moubctez Exp $

.if !defined(GIMP_CURRENT_BUILDLINK2_MK)
GIMP_CURRENT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gimp-current
BUILDLINK_DEPENDS.gimp-current?=	gimp-current>=1.3.15
BUILDLINK_PKGSRCDIR.gimp-current?=	../../wip/gimp-current

EVAL_PREFIX+=	BUILDLINK_PREFIX.gimp-current=gimp-current
BUILDLINK_PREFIX.gimp-current_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gimp-current+=	include/gimp-1.3/*
BUILDLINK_FILES.gimp-current+=	lib/libgck*
BUILDLINK_FILES.gimp-current+=	lib/libgimp*

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/mpeg-lib/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	gimp-current-buildlink

gimp-current-buildlink: _BUILDLINK_USE

.endif	# GIMP_CURRENT_BUILDLINK2_MK
