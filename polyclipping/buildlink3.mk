# $NetBSD$

BUILDLINK_TREE+=	polyclipping

.if !defined(POLYCLIPPING_BUILDLINK3_MK)
POLYCLIPPING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polyclipping+=	polyclipping>=6.4
BUILDLINK_PKGSRCDIR.polyclipping?=	../../wip/polyclipping
.endif	# POLYCLIPPING_BUILDLINK3_MK

BUILDLINK_TREE+=	-polyclipping
