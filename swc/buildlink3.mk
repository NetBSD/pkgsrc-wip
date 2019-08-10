# $NetBSD$

BUILDLINK_TREE+=	swc

.if !defined(SWC_BUILDLINK3_MK)
SWC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swc+=	swc>=0.0.20190810
BUILDLINK_PKGSRCDIR.swc?=	../../wip/swc

.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../wip/wayland/buildlink3.mk"
.include "../../wip/wld/buildlink3.mk"
.endif	# SWC_BUILDLINK3_MK

BUILDLINK_TREE+=	-swc
