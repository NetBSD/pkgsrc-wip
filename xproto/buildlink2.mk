# $NetBSD: buildlink2.mk,v 1.1 2003/11/26 23:54:45 xtraeme Exp $
#
# This Makefile fragment is included by packages that use xtrans.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(XTRANS_BUILDLINK2_MK)
XTRANS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xtrans
BUILDLINK_DEPENDS.xtrans?=		xtrans>=0.1
BUILDLINK_PKGSRCDIR.xtrans?=		../../wip/xproto

EVAL_PREFIX+=	BUILDLINK_PREFIX.xtrans=xtrans
BUILDLINK_PREFIX.xtrans_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.xtrans+=	include/X11/X.h
BUILDLINK_FILES.xtrans+=	include/X11/Xarch.h
BUILDLINK_FILES.xtrans+=	include/X11/Xatom.h
BUILDLINK_FILES.xtrans+=	include/X11/Xdefs.h
BUILDLINK_FILES.xtrans+=	include/X11/Xfuncproto.h
BUILDLINK_FILES.xtrans+=	include/X11/Xfuncs.h
BUILDLINK_FILES.xtrans+=	include/X11/Xmd.h
BUILDLINK_FILES.xtrans+=	include/X11/Xos.h
BUILDLINK_FILES.xtrans+=	include/X11/Xos_r.h
BUILDLINK_FILES.xtrans+=	include/X11/Xosdefs.h
BUILDLINK_FILES.xtrans+=	include/X11/Xpoll.h
BUILDLINK_FILES.xtrans+=	include/X11/Xproto.h
BUILDLINK_FILES.xtrans+=	include/X11/Xprotostr.h
BUILDLINK_FILES.xtrans+=	include/X11/Xthreads.h
BUILDLINK_FILES.xtrans+=	include/X11/keysym.h
BUILDLINK_FILES.xtrans+=	include/X11/keysymdef.h


BUILDLINK_TARGETS+=	xtrans-buildlink

xtrans-buildlink: _BUILDLINK_USE

.endif	# XTRANS_BUILDLINK2_MK
