# $NetBSD: buildlink2.mk,v 1.2 2003/06/03 02:45:28 xtraeme Exp $
#
# This Makefile fragment is included by packages that use directfb.
#
# This file was created automatically using createbuildlink 2.5.
#

.if !defined(DIRECTFB_BUILDLINK2_MK)
DIRECTFB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			directfb
BUILDLINK_DEPENDS.directfb?=		directfb>=0.9.17
BUILDLINK_PKGSRCDIR.directfb?=		../../wip/directfb

EVAL_PREFIX+=	BUILDLINK_PREFIX.directfb=directfb
BUILDLINK_PREFIX.directfb_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/*.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/*.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/display/*.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/gfx/*.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/input/*.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/media/*.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/misc/*.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/windows/idirectfbwindow.h
BUILDLINK_FILES.directfb+=	include/directfb/*.h
BUILDLINK_FILES.directfb+=	lib/${PKGNAME}/interfaces/IDirectFBFont/libidirectfbfont_default.*
BUILDLINK_FILES.directfb+=	lib/${PKGNAME}/interfaces/IDirectFBFont/libidirectfbfont_ft2.*
BUILDLINK_FILES.directfb+=	lib/${PKGNAME}/interfaces/IDirectFBImageProvider/libidirectfbimageprovider_gif.*
BUILDLINK_FILES.directfb+=	lib/${PKGNAME}/interfaces/IDirectFBImageProvider/libidirectfbimageprovider_jpeg.*
BUILDLINK_FILES.directfb+=	lib/${PKGNAME}/interfaces/IDirectFBImageProvider/libidirectfbimageprovider_mpeg2.*
BUILDLINK_FILES.directfb+=	lib/${PKGNAME}/interfaces/IDirectFBImageProvider/libidirectfbimageprovider_png.*
BUILDLINK_FILES.directfb+=	lib/libdirectfb-0.9.*
BUILDLINK_FILES.directfb+=	lib/libdirectfb.*
BUILDLINK_FILES.directfb+=	lib/pkgconfig/directfb-internal.pc
BUILDLINK_FILES.directfb+=	lib/pkgconfig/directfb.pc

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"

BUILDLINK_TARGETS+=	directfb-buildlink

directfb-buildlink: _BUILDLINK_USE

.endif	# DIRECTFB_BUILDLINK2_MK
