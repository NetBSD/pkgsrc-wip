# $NetBSD$

BUILDLINK_TREE+=	ccnet-server

.if !defined(CCNET_SERVER_BUILDLINK3_MK)
CCNET_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ccnet-server+=	ccnet-server>=6.0.0
BUILDLINK_PKGSRCDIR.ccnet-server?=	../../wip/ccnet-server
.endif	# CCNET_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-ccnet-server
