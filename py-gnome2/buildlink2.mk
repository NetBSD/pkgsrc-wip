# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/04/07 06:07:56 marc Exp $

.if !defined(PYGNOME2_BUILDLINK2_MK)
PYGNOME2_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pygnome2
BUILDLINK_DEPENDS.pygnome2?=		${PYPKGPREFIX}-gnome2>=1.99.16
BUILDLINK_PKGSRCDIR.pygnome2?=		../../wip/py-gnome2

EVAL_PREFIX+=	BUILDLINK_PREFIX.pygnome2=${PYPKGPREFIX}-gnome2
BUILDLINK_PREFIX.pygnome2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pygnome2+=	lib/pkgconfig/gnome-python-2.0.pc

.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../x11/libzvt/buildlink2.mk"
.include "../../x11/gnome-panel/buildlink2.mk"
.include "../../www/libgtkhtml/buildlink2.mk"
.include "../../wip/py-ORBit/buildlink2.mk"
.include "../../wip/py-gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	pygnome2-buildlink

pygnome2-buildlink: _BUILDLINK_USE

.endif	# PYGNOME2_BUILDLINK2_MK
