# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/07/27 06:03:36 bencollver Exp $
#
# This Makefile fragment is included by packages that use svgalib.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(SVGALIB_BUILDLINK2_MK)
SVGALIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			svgalib
BUILDLINK_DEPENDS.svgalib?=		svgalib>=1.4.2
BUILDLINK_PKGSRCDIR.svgalib?=		../../graphics/svgalib

EVAL_PREFIX+=	BUILDLINK_PREFIX.svgalib=svgalib
BUILDLINK_PREFIX.svgalib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.svgalib+=	include/linux/kd.h
BUILDLINK_FILES.svgalib+=	include/linux/keyboard.h
BUILDLINK_FILES.svgalib+=	include/vga.h
BUILDLINK_FILES.svgalib+=	include/vgagl.h
BUILDLINK_FILES.svgalib+=	include/vgajoystick.h
BUILDLINK_FILES.svgalib+=	include/vgakeyboard.h
BUILDLINK_FILES.svgalib+=	include/vgamouse.h
BUILDLINK_FILES.svgalib+=	lib/libvga.*
BUILDLINK_FILES.svgalib+=	lib/libvgagl.*

BUILDLINK_TARGETS+=	svgalib-buildlink

svgalib-buildlink: _BUILDLINK_USE

.endif	# SVGALIB_BUILDLINK2_MK
