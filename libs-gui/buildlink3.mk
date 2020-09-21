# $NetBSD$

BUILDLINK_TREE+=	libs-gui

.if !defined(LIBS_GUI_BUILDLINK3_MK)
LIBS_GUI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libs-gui+=	libs-gui>=0.28
BUILDLINK_ABI_DEPENDS.libs-gui+=	libs-gui>=0.28
BUILDLINK_PKGSRCDIR.libs-gui?=		../../wip/libs-gui

.include "../../devel/gnustep-base/buildlink3.mk"
.endif # LIBS_GUI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libs-gui
