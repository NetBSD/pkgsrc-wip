# $NetBSD$

BUILDLINK_TREE+=	ccnet

.if !defined(CCNET_BUILDLINK3_MK)
CCNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ccnet+=	ccnet-server>=6.0.0
BUILDLINK_PKGSRCDIR.ccnet?=	../../wip/ccnet-server
.endif	# CCNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-ccnet
