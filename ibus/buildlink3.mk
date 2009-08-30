# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/08/30 08:28:05 obache Exp $
#

BUILDLINK_TREE+=	ibus

.if !defined(IBUS_BUILDLINK3_MK)
IBUS_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.ibus+=	${PYPKGPREFIX}-ibus>=1.1.0.20090612
BUILDLINK_PKGSRCDIR.ibus?=	../../wip/ibus

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif	# IBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ibus
