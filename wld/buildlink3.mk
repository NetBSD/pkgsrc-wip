# $NetBSD$

BUILDLINK_TREE+=	wld

.if !defined(WLD_BUILDLINK3_MK)
WLD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wld+=	wld>=0.0.20190810
BUILDLINK_PKGSRCDIR.wld?=	../../wip/wld

.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.endif	# WLD_BUILDLINK3_MK

BUILDLINK_TREE+=	-wld
