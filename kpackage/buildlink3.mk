# $NetBSD$

BUILDLINK_TREE+=	kpackage

.if !defined(KPACKAGE_BUILDLINK3_MK)
KPACKAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kpackage+=	kpackage>=5.19.0
BUILDLINK_PKGSRCDIR.kpackage?=	../../wip/kpackage

.include "../../wip/karchive/buildlink3.mk"
.include "../../wip/kconfig/buildlink3.mk"
.include "../../wip/kcoreaddons/buildlink3.mk"
.include "../../wip/ki18n/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KPACKAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kpackage
