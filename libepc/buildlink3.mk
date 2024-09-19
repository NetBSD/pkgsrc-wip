# $NetBSD: buildlink3.mk,v 1.6 2015/06/07 14:24:48 yrmt Exp $

BUILDLINK_TREE+=	libepc

.if !defined(LIBEPC_BUILDLINK3_MK)
LIBEPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libepc+=	libepc>=0.3.11
BUILDLINK_ABI_DEPENDS.libepc?=	libepc>=0.3.11nb1
BUILDLINK_PKGSRCDIR.libepc?=	../../wip/libepc

.include "../../x11/gtk3/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.endif	# LIBEPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libepc
