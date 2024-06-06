# $NetBSD$

BUILDLINK_TREE+=	layer-shell-qt

.if !defined(LAYER_SHELL_QT_BUILDLINK3_MK)
LAYER_SHELL_QT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.layer-shell-qt+=	layer-shell-qt>=6.0.5
BUILDLINK_PKGSRCDIR.layer-shell-qt?=	../../wip/layer-shell-qt6

.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/qt6-qtwayland/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.endif	# LAYER_SHELL_QT_BUILDLINK3_MK

BUILDLINK_TREE+=	-layer-shell-qt
