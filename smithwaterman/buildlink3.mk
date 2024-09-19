# $NetBSD$

BUILDLINK_TREE+=	smithwaterman

.if !defined(SMITHWATERMAN_BUILDLINK3_MK)
SMITHWATERMAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.smithwaterman+=	smithwaterman>=0.0.0.20160702
BUILDLINK_PKGSRCDIR.smithwaterman?=	../../wip/smithwaterman
.endif	# SMITHWATERMAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-smithwaterman
