# $NetBSD: buildlink2.mk,v 1.2 2004/01/26 00:51:13 minskim Exp $
#
# This Makefile fragment is included by packages that use xextensions.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(XEXTENSIONS_BUILDLINK2_MK)
XEXTENSIONS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xextensions
BUILDLINK_DEPENDS.xextensions?=		xextensions>=1.0
BUILDLINK_PKGSRCDIR.xextensions?=		../../wip/xextensions

EVAL_PREFIX+=	BUILDLINK_PREFIX.xextensions=xextensions
BUILDLINK_PREFIX.xextensions_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.xextensions+=	include/X11/extensions/MITMisc.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/XEVI.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/XEVIstr.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/XI.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/XInput.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/XIproto.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/XKB.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/XKBgeom.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/XKBproto.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/XKBsrv.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/XKBstr.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/XLbx.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/XShm.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/XTest.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/Xag.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/Xagsrv.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/Xagstr.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/Xcup.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/Xcupstr.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/Xdbe.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/Xdbeproto.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/Xext.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/Xv.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/XvMC.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/XvMCproto.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/Xvproto.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/bigreqstr.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/dpms.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/dpmsstr.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/extutil.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/lbxbuf.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/lbxbufstr.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/lbxdeltastr.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/lbximage.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/lbxopts.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/lbxstr.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/lbxzlib.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/mitmiscstr.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/multibuf.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/multibufst.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/saver.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/saverproto.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/security.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/securstr.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/shape.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/shapestr.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/shmstr.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/sync.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/syncstr.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/xcmiscstr.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/xtestext1.h
BUILDLINK_FILES.xextensions+=	include/X11/extensions/xteststr.h

BUILDLINK_TARGETS+=	xextensions-buildlink

xextensions-buildlink: _BUILDLINK_USE

.endif	# XEXTENSIONS_BUILDLINK2_MK
