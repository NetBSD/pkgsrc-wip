# $NetBSD$

BUILDLINK_TREE+=	graphene

.if !defined(GRAPHENE_BUILDLINK3_MK)
GRAPHENE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.graphene+=	graphene>=1.10.0
BUILDLINK_PKGSRCDIR.graphene?=	../../wip/graphene
.endif	# GRAPHENE_BUILDLINK3_MK

BUILDLINK_TREE+=	-graphene
