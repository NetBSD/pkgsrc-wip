# $NetBSD$

BUILDLINK_TREE+=	plasma6-layer-shell-qt

.if !defined(PLASMA6_LAYER_SHELL_QT_BUILDLINK3_MK)
PLASMA6_LAYER_SHELL_QT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plasma6-layer-shell-qt+=	plasma6-layer-shell-qt>=6.0.5
BUILDLINK_PKGSRCDIR.plasma6-layer-shell-qt?=	../../wip/layer-shell-qt6

.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/qt6-qtwayland/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.endif	# PLASMA6_LAYER_SHELL_QT_BUILDLINK3_MK

BUILDLINK_TREE+=	-plasma6-layer-shell-qt
