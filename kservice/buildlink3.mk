# $NetBSD$

BUILDLINK_TREE+=	kservice

.if !defined(KSERVICE_BUILDLINK3_MK)
KSERVICE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kservice+=	kservice>=5.18.0
BUILDLINK_PKGSRCDIR.kservice?=	../../wip/kservice

.include "../../wip/kconfig/buildlink3.mk"
.include "../../wip/kcrash/buildlink3.mk"
.include "../../wip/kdbusaddons/buildlink3.mk"
.include "../../wip/ki18n/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KSERVICE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kservice
