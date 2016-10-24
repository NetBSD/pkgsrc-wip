# $NetBSD$

BUILDLINK_TREE+=	seafile-ccnet
BUILDLINK_TREE+=	libccnet
BUILDLINK_TREE+=	ccnet

.if !defined(SEAFILE_CCNET_BUILDLINK3_MK)
SEAFILE_CCNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.seafile-ccnet+=	seafile-ccnet>=6.00
BUILDLINK_PKGSRCDIR.seafile-ccnet?=	../../wip/seafile-ccnet
.endif	# SEAFILE_CCNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-seafile-ccnet
BUILDLINK_TREE+=	-libccnet
BUILDLINK_TREE+=	-ccnet
