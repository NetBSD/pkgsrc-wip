# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/11/04 05:04:31 mpasternak Exp $

.if !defined(PXLIB_BUILDLINK2_MK)
PXLIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		pxlib
BUILDLINK_DEPENDS.pxlib?=	pxlib>=0.2.0
BUILDLINK_PKGSRCDIR.pxlib?=	../../wip/pxlib

EVAL_PREFIX+=			BUILDLINK_PREFIX.pxlib=pxlib
BUILDLINK_PREFIX.pxlib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pxlib=	include/paradox.h include/paradox-gsf.h include/pxversion.h
BUILDLINK_FILES.pxlib+=	lib/libpx.*

.include "../../converters/libiconv/buildlink2.mk"
.include "../../converters/recode/buildlink2.mk"

BUILDLINK_TARGETS+=	pxlib-buildlink

pxlib-buildlink: _BUILDLINK_USE

.endif	# PXLIB_BUILDLINK2_MK
