# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/11/29 18:04:07 daprice Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.shapelib?=	build

.if !defined(SHAPELIB_BUILDLINK2_MK)
SHAPELIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		shapelib
BUILDLINK_DEPENDS.shapelib?=	shapelib>=1.2.10
BUILDLINK_PKGSRCDIR.shapelib?=	../../wip/shapelib

EVAL_PREFIX+=	BUILDLINK_PREFIX.shapelib=shapelib
BUILDLINK_PREFIX.shapelib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.shapelib+=	include/libshp/shapefil.h
BUILDLINK_FILES.shapelib+=	lib/libshp.*
BUILDLINK_TARGETS+=	shapelib-buildlink

shapelib-buildlink: _BUILDLINK_USE

.endif	# SHAPELIB_BUILDLINK2_MK
