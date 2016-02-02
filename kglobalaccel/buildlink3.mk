# $NetBSD$

BUILDLINK_TREE+=	kglobalaccel

.if !defined(KGLOBALACCEL_BUILDLINK3_MK)
KGLOBALACCEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kglobalaccel+=	kglobalaccel>=5.18.0
BUILDLINK_PKGSRCDIR.kglobalaccel?=	../../wip/kglobalaccel

.include "../../wip/kconfig/buildlink3.mk"
.include "../../wip/kcrash/buildlink3.mk"
.include "../../wip/kdbusaddons/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KGLOBALACCEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-kglobalaccel
