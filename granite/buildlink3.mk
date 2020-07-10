# $NetBSD$

BUILDLINK_TREE+=	granite

.if !defined(GRANITE_BUILDLINK3_MK)
GRANITE_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.granite?=	build

BUILDLINK_API_DEPENDS.granite+=	granite>=5.5.0
BUILDLINK_PKGSRCDIR.granite?=	../../wip/granite

.include "../../x11/gtk3/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.endif	# GRANITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-granite
