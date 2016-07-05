# $NetBSD$

BUILDLINK_TREE+=	opencascade

.if !defined(OPENCASCADE_BUILDLINK3_MK)
OPENCASCADE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencascade+=	opencascade>=7.0.0
BUILDLINK_PKGSRCDIR.opencascade?=	../../wip/opencascade

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.endif	# OPENCASCADE_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencascade
