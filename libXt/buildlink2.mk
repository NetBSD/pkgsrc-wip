# $NetBSD: buildlink2.mk,v 1.1 2004/01/31 08:50:48 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use libXt.
#
# This file was created automatically using createbuildlink 2.9.
#

.if !defined(LIBXT_BUILDLINK2_MK)
LIBXT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libXt
BUILDLINK_DEPENDS.libXt?=		libXt>=0.1.4
BUILDLINK_PKGSRCDIR.libXt?=		../../wip/libXt

EVAL_PREFIX+=	BUILDLINK_PREFIX.libXt=libXt
BUILDLINK_PREFIX.libXt_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libXt+=	include/X11/Composite.h
BUILDLINK_FILES.libXt+=	include/X11/CompositeP.h
BUILDLINK_FILES.libXt+=	include/X11/ConstrainP.h
BUILDLINK_FILES.libXt+=	include/X11/Constraint.h
BUILDLINK_FILES.libXt+=	include/X11/Core.h
BUILDLINK_FILES.libXt+=	include/X11/CoreP.h
BUILDLINK_FILES.libXt+=	include/X11/Intrinsic.h
BUILDLINK_FILES.libXt+=	include/X11/IntrinsicP.h
BUILDLINK_FILES.libXt+=	include/X11/Object.h
BUILDLINK_FILES.libXt+=	include/X11/ObjectP.h
BUILDLINK_FILES.libXt+=	include/X11/RectObj.h
BUILDLINK_FILES.libXt+=	include/X11/RectObjP.h
BUILDLINK_FILES.libXt+=	include/X11/Shell.h
BUILDLINK_FILES.libXt+=	include/X11/ShellP.h
BUILDLINK_FILES.libXt+=	include/X11/StringDefs.h
BUILDLINK_FILES.libXt+=	include/X11/Vendor.h
BUILDLINK_FILES.libXt+=	include/X11/VendorP.h
BUILDLINK_FILES.libXt+=	lib/libXt.*

.include "../../wip/libICE/buildlink2.mk"
.include "../../wip/libSM/buildlink2.mk"
.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"
.include "../../wip/xextensions/buildlink2.mk"

BUILDLINK_TARGETS+=	libXt-buildlink

libXt-buildlink: _BUILDLINK_USE

.endif	# LIBXT_BUILDLINK2_MK
