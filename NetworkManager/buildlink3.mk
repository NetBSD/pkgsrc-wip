# $NetBSD$

BUILDLINK_TREE+=	NetworkManager

.if !defined(NETWORKMANAGER_BUILDLINK3_MK)
NETWORKMANAGER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.NetworkManager+=	NetworkManager>=1.50.0
BUILDLINK_PKGSRCDIR.NetworkManager?=	../../wip/NetworkManager

#.include "../../devel/libuuid/buildlink3.mk"
#.include "../../sysutils/libudev/buildlink3.mk"
#.include "../../sysutils/dbus/buildlink3.mk"
#.include "../../wip/libndp/buildlink3.mk"
#.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/gobject-introspection/buildlink3.mk"
#.include "../../security/polkit/buildlink3.mk"
.endif	# NETWORKMANAGER_BUILDLINK3_MK

BUILDLINK_TREE+=	-NetworkManager
