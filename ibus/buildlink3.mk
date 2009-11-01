# $NetBSD: buildlink3.mk,v 1.2 2009/11/01 08:48:40 obache Exp $
#

BUILDLINK_TREE+=	ibus

.if !defined(IBUS_BUILDLINK3_MK)
IBUS_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.ibus+=	${PYPKGPREFIX}-ibus>=1.2.0.20091024
BUILDLINK_PKGSRCDIR.ibus?=	../../wip/ibus

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif	# IBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ibus
