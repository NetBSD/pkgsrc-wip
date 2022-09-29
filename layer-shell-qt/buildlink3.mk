# $NetBSD$

BUILDLINK_TREE+=	layer-shell-qt

.if !defined(LAYER_SHELL_QT_BUILDLINK3_MK)
LAYER_SHELL_QT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.layer-shell-qt+=	layer-shell-qt>=5.24.6
BUILDLINK_PKGSRCDIR.layer-shell-qt?=	../../wip/layer-shell-qt

#.include "../../devel/wayland-protocols/buildlink3.mk"
#.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
#.include "../../x11/qt5-qtwayland/buildlink3.mk"
#.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LAYER_SHELL_QT_BUILDLINK3_MK

BUILDLINK_TREE+=	-layer-shell-qt
