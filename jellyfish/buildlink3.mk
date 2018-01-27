# $NetBSD$

BUILDLINK_TREE+=	jellyfish

.if !defined(JELLYFISH_BUILDLINK3_MK)
JELLYFISH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jellyfish+=	jellyfish>=1.1.11
BUILDLINK_PKGSRCDIR.jellyfish?=		../../wip/jellyfish
.endif	# JELLYFISH_BUILDLINK3_MK

BUILDLINK_TREE+=	-jellyfish
