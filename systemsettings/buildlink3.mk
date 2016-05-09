# $NetBSD$

BUILDLINK_TREE+=	systemsettings

.if !defined(SYSTEMSETTINGS_BUILDLINK3_MK)
SYSTEMSETTINGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.systemsettings+=	systemsettings>=5.6.3
BUILDLINK_PKGSRCDIR.systemsettings?=	../../wip/systemsettings

.include "../../wip/kcmutils/buildlink3.mk"
.include "../../wip/khtml/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# SYSTEMSETTINGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-systemsettings
