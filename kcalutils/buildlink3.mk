# $NetBSD$

BUILDLINK_TREE+=	kcalutils

.if !defined(KCALUTILS_BUILDLINK3_MK)
KCALUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcalutils+=	kcalutils>=17.12.1
BUILDLINK_PKGSRCDIR.kcalutils?=	../../wip/kcalutils

.include "../../wip/kcalcore/buildlink3.mk"
.include "../../wip/kidentitymanagement/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCALUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcalutils
