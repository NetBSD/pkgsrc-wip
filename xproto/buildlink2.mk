# $NetBSD: buildlink2.mk,v 1.5 2004/05/08 21:30:28 minskim Exp $
#
# This Makefile fragment is included by packages that use xproto.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(XPROTO_BUILDLINK2_MK)
XPROTO_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xproto
BUILDLINK_DEPENDS.xproto?=		xproto>=6.6
BUILDLINK_PKGSRCDIR.xproto?=		../../wip/xproto
BUILDLINK_DEPMETHOD.xproto?=		build

EVAL_PREFIX+=	BUILDLINK_PREFIX.xproto=xproto
BUILDLINK_PREFIX.xproto_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.xproto+=	include/X11/X.h
BUILDLINK_FILES.xproto+=	include/X11/XF86keysym.h
BUILDLINK_FILES.xproto+=	include/X11/Xarch.h
BUILDLINK_FILES.xproto+=	include/X11/Xatom.h
BUILDLINK_FILES.xproto+=	include/X11/Xdefs.h
BUILDLINK_FILES.xproto+=	include/X11/Xfuncproto.h
BUILDLINK_FILES.xproto+=	include/X11/Xfuncs.h
BUILDLINK_FILES.xproto+=	include/X11/Xmd.h
BUILDLINK_FILES.xproto+=	include/X11/Xos.h
BUILDLINK_FILES.xproto+=	include/X11/Xos_r.h
BUILDLINK_FILES.xproto+=	include/X11/Xosdefs.h
BUILDLINK_FILES.xproto+=	include/X11/Xpoll.h
BUILDLINK_FILES.xproto+=	include/X11/Xproto.h
BUILDLINK_FILES.xproto+=	include/X11/Xprotostr.h
BUILDLINK_FILES.xproto+=	include/X11/Xthreads.h
BUILDLINK_FILES.xproto+=	include/X11/keysym.h
BUILDLINK_FILES.xproto+=	include/X11/keysymdef.h

BUILDLINK_TARGETS+=	xproto-buildlink

xproto-buildlink: _BUILDLINK_USE

.endif	# XPROTO_BUILDLINK2_MK
