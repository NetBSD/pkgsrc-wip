# $NetBSD: buildlink3.mk,v 1.2 2010/05/02 14:31:42 thomasklausner Exp $

BUILDLINK_TREE+=	libepc

.if !defined(LIBEPC_BUILDLINK3_MK)
LIBEPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libepc+=	libepc>=0.3.11
BUILDLINK_PKGSRCDIR.libepc?=	../../wip/libepc

.include "../../net/libsoup24/buildlink3.mk"
.endif	# LIBEPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libepc
