# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/11/10 22:40:43 daprice Exp $
#
# This Makefile fragment is included by packages that use emboss-base.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(EMBOSS_BASE_BUILDLINK2_MK)
EMBOSS_BASE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			emboss-base
BUILDLINK_DEPENDS.emboss-base?=		emboss-base>=2.7.1
BUILDLINK_PKGSRCDIR.emboss-base?=	../../wip/emboss-base

EVAL_PREFIX+=	BUILDLINK_PREFIX.emboss-base=emboss-base
BUILDLINK_PREFIX.emboss-base_DEFAULT=	${LOCALBASE}/share/EMBOSS

BUILDLINK_FILES.emboss-base=	     include/*.h
BUILDLINK_FILES.emboss-base+=        lib/libajax.*
BUILDLINK_FILES.emboss-base+=        lib/libajaxg.*
BUILDLINK_FILES.emboss-base+=        lib/libnucleus.*
BUILDLINK_FILES.emboss-base+=        lib/libplplot.*

BUILDLINK_TARGETS+=	emboss-base-buildlink

emboss-base-buildlink: _BUILDLINK_USE

.endif	# EMBOSS_BASE_BUILDLINK2_MK
