# $NetBSD: buildlink3.mk,v 1.3 2010/06/13 22:47:10 thomasklausner Exp $

BUILDLINK_TREE+=	libepc

.if !defined(LIBEPC_BUILDLINK3_MK)
LIBEPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libepc+=	libepc>=0.3.11
BUILDLINK_ABI_DEPENDS.libepc?=	libepc>=0.3.11nb1
BUILDLINK_PKGSRCDIR.libepc?=	../../wip/libepc

.include "../../net/libsoup24/buildlink3.mk"
.endif	# LIBEPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libepc
