# $NetBSD: buildlink2.mk,v 1.2 2003/10/07 16:33:03 xtraeme Exp $
#
# This Makefile fragment is included by packages that use freeglut.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(FREEGLUT_BUILDLINK2_MK)
FREEGLUT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			freeglut
BUILDLINK_DEPENDS.freeglut?=		freeglut>=2.0.0rc2
BUILDLINK_PKGSRCDIR.freeglut?=		../../wip/freeglut

EVAL_PREFIX+=	BUILDLINK_PREFIX.freeglut=freeglut
BUILDLINK_PREFIX.freeglut_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.freeglut+=	include/GL/freeglut.h
BUILDLINK_FILES.freeglut+=	include/GL/freeglut_ext.h
BUILDLINK_FILES.freeglut+=	include/GL/glut.h
BUILDLINK_FILES.freeglut+=	lib/libglut.*

BUILDLINK_TARGETS+=	freeglut-buildlink

freeglut-buildlink: _BUILDLINK_USE

.endif	# FREEGLUT_BUILDLINK2_MK
