# $NetBSD$

BUILDLINK_TREE+=	tllist

.if !defined(TLLIST_BUILDLINK3_MK)
TLLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tllist+=	tllist>=1.1.0
BUILDLINK_PKGSRCDIR.tllist?=	../../wip/tllist
.endif	# TLLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-tllist
