# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/04/14 05:29:56 xtraeme Exp $
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
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/clipboard.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/colorhash.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/core.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/core_parts.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/core_system.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/coredefs.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/coretypes.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/fonts.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/fusion/arena.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/fusion/fusion.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/fusion/fusion_types.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/fusion/list.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/fusion/lock.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/fusion/object.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/fusion/property.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/fusion/reactor.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/fusion/ref.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/fusion/shmalloc.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/gfxcard.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/graphics_driver.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/input.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/input_driver.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/layers.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/modules.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/palette.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/sig.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/state.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/surfacemanager.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/surfaces.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/system.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/thread.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/core/windows.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/directfb_internals.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/directfb_version.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/display/idirectfbdisplaylayer.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/display/idirectfbpalette.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/display/idirectfbsurface.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/display/idirectfbsurface_layer.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/display/idirectfbsurface_window.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/gfx/clip.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/gfx/convert.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/gfx/util.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/idirectfb.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/input/idirectfbinputbuffer.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/input/idirectfbinputdevice.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/interface_implementation.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/media/idirectfbdatabuffer.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/media/idirectfbfont.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/media/idirectfbimageprovider.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/media/idirectfbvideoprovider.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/misc/conf.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/misc/cpu_accel.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/misc/gfx_util.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/misc/mem.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/misc/memcpy.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/misc/tree.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/misc/utf8.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/misc/util.h
BUILDLINK_FILES.directfb+=	include/directfb-internal/windows/idirectfbwindow.h
BUILDLINK_FILES.directfb+=	include/directfb/dfb_types.h
BUILDLINK_FILES.directfb+=	include/directfb/directfb.h
BUILDLINK_FILES.directfb+=	include/directfb/directfb_keyboard.h
BUILDLINK_FILES.directfb+=	include/directfb/directfb_keynames.h
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
