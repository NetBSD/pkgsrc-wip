# $NetBSD: buildlink2.mk,v 1.4 2004/02/11 04:26:20 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use libXmu.
#
# This file was created automatically using createbuildlink 2.9.
#

.if !defined(LIBXMU_BUILDLINK2_MK)
LIBXMU_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libXmu
BUILDLINK_DEPENDS.libXmu?=		libXmu>=6.2.1nb2
BUILDLINK_PKGSRCDIR.libXmu?=		../../wip/libXmu

EVAL_PREFIX+=	BUILDLINK_PREFIX.libXmu=libXmu
BUILDLINK_PREFIX.libXmu_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/Atoms.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/CharSet.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/CloseHook.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/Converters.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/CurUtil.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/CvtCache.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/DisplayQue.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/Drawing.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/Editres.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/EditresP.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/Error.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/ExtAgent.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/Initer.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/Lookup.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/Misc.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/StdCmap.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/StdSel.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/SysUtil.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/WidgetNode.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/WinUtil.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/Xct.h
BUILDLINK_FILES.libXmu+=	include/X11/Xmu/Xmu.h
BUILDLINK_FILES.libXmu+=	lib/libXmu.*
BUILDLINK_FILES.libXmu+=	lib/libXmuu.*

.include "../../wip/libXt/buildlink2.mk"
.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/libXext/buildlink2.mk"
.include "../../wip/xextensions/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"

# libXmu uses libXext's XShapeCombineMask()
LDFLAGS+=			-lXext

.include "../../mk/pthread.buildlink2.mk"
LIBS+=				${BUILDLINK_LDFLAGS.pthread}

BUILDLINK_TARGETS+=	libXmu-buildlink

libXmu-buildlink: _BUILDLINK_USE

.endif	# LIBXMU_BUILDLINK2_MK
