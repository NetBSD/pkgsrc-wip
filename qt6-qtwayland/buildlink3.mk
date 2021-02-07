# $NetBSD$

BUILDLINK_TREE+=	qt6-qtwayland

.if !defined(QT6_QTWAYLAND_BUILDLINK3_MK)
QT6_QTWAYLAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtwayland+=	qt6-qtwayland>=6.0.1
BUILDLINK_PKGSRCDIR.qt6-qtwayland?=	../../wip/qt6-qtwayland

BUILDLINK_LIBDIRS.qt6-qtwayland+=	qt6/plugins/platforms
BUILDLINK_LIBDIRS.qt6-qtwayland+=	qt6/plugins/wayland-decoration-client
BUILDLINK_LIBDIRS.qt6-qtwayland+=	qt6/plugins/wayland-graphics-integration-client
BUILDLINK_LIBDIRS.qt6-qtwayland+=	qt6/plugins/wayland-graphics-integration-server
BUILDLINK_LIBDIRS.qt6-qtwayland+=	qt6/plugins/wayland-shell-integration


.include "../../devel/wayland/buildlink3.mk"
.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.endif	# QT6_QTWAYLAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtwayland
