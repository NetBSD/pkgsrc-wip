# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/11/19 19:26:01 daprice Exp $
#
# This Makefile fragment is included by packages that use jalview_binary.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(JALVIEW_BINARY_BUILDLINK2_MK)
JALVIEW_BINARY_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			jalview_binary
BUILDLINK_DEPENDS.jalview_binary?=		jalview_binary>=1.8
BUILDLINK_PKGSRCDIR.jalview_binary?=		../../wip/jalview

EVAL_PREFIX+=	BUILDLINK_PREFIX.jalview_binary=jalview_binary
BUILDLINK_PREFIX.jalview_binary_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.jalview_binary=		lib/java/jalview.jar
BUILDLINK_FILES.jalview_binary+=	lib/java/jalview_1.8.jar

BUILDLINK_TARGETS+=	jalview_binary-buildlink

jalview_binary-buildlink: _BUILDLINK_USE

.endif	# JALVIEW_BINARY_BUILDLINK2_MK
