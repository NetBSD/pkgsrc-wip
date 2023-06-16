# $NetBSD: buildlink3.mk,v 1.5 2023/05/06 19:08:54 ryoon Exp $

BUILDLINK_TREE+=	spice-server

.if !defined(SPICE_SERVER_BUILDLINK3_MK)
SPICE_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spice-server+=	spice-server>=0.14.2
BUILDLINK_ABI_DEPENDS.spice-server+=	spice-server>=0.14.3nb2
BUILDLINK_PKGSRCDIR.spice-server?=	../../sysutils/spice-server

.include "../../audio/libopus/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/spice-protocol/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.endif	# SPICE_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-spice-server
