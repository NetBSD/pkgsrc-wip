# $NetBSD$

BUILDLINK_TREE+=	mtxclient

.if !defined(MTXCLIENT_BUILDLINK3_MK)
MTXCLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mtxclient+=	mtxclient>=0.10.1
BUILDLINK_PKGSRCDIR.mtxclient?=		../../wip/mtxclient

.endif	# MTXCLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mtxclient
