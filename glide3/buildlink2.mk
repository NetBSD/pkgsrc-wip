# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/10/16 02:21:34 cetrox Exp $
#
# This Makefile fragment is included by packages that use Glide_V3-2.60.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(GLIDE_V3_2.60_BUILDLINK2_MK)
GLIDE_V3_2.60_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			Glide_V3-2.60
BUILDLINK_DEPENDS.Glide_V3-2.60?=		Glide_V3-2.60>=18
BUILDLINK_PKGSRCDIR.Glide_V3-2.60?=		../../wip/glide3

EVAL_PREFIX+=	BUILDLINK_PREFIX.Glide_V3-2.60=Glide_V3-2.60
BUILDLINK_PREFIX.Glide_V3-2.60_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.Glide_V3-2.60+=	lib/libglide.*
BUILDLINK_FILES.Glide_V3-2.60+=	lib/libglide3.*
BUILDLINK_FILES.Glide_V3-2.60+=	lib/libtexus.*

BUILDLINK_TARGETS+=	Glide_V3-2.60-buildlink

Glide_V3-2.60-buildlink: _BUILDLINK_USE

.endif	# GLIDE_V3_2.60_BUILDLINK2_MK
