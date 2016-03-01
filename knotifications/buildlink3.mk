# $NetBSD$

BUILDLINK_TREE+=	knotifications

.if !defined(KNOTIFICATIONS_BUILDLINK3_MK)
KNOTIFICATIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.knotifications+=	knotifications>=5.19.0
BUILDLINK_PKGSRCDIR.knotifications?=	../../wip/knotifications

.include "../../wip/kcodecs/buildlink3.mk"
.include "../../wip/kconfig/buildlink3.mk"
.include "../../wip/kcoreaddons/buildlink3.mk"
.include "../../wip/kwindowsystem/buildlink3.mk"
.include "../../multimedia/phonon-qt5/buildlink3.mk"
.include "../../devel/libdbusmenu-qt5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KNOTIFICATIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-knotifications
