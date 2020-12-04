# $NetBSD$

BUILDLINK_TREE+=	systemsettings

.if !defined(SYSTEMSETTINGS_BUILDLINK3_MK)
SYSTEMSETTINGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.systemsettings+=	systemsettings>=5.6.3
BUILDLINK_ABI_DEPENDS.systemsettings?=	systemsettings>=5.18.5nb1
BUILDLINK_PKGSRCDIR.systemsettings?=	../../wip/systemsettings

.include "../../devel/kcmutils/buildlink3.mk"
.include "../../www/khtml/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# SYSTEMSETTINGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-systemsettings
