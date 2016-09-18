# $NetBSD$

BUILDLINK_TREE+=	adaptagrams

.if !defined(ADAPTAGRAMS_BUILDLINK3_MK)
ADAPTAGRAMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.adaptagrams+=	adaptagrams>=0.20160901
BUILDLINK_PKGSRCDIR.adaptagrams?=	../../wip/adaptagrams
.endif	# ADAPTAGRAMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-adaptagrams
