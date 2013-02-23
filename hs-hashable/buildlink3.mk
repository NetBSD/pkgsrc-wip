# $NetBSD: buildlink3.mk,v 1.4 2013/02/23 14:53:28 phonohawk Exp $

BUILDLINK_TREE+=	hs-hashable

.if !defined(HS_HASHABLE_BUILDLINK3_MK)
HS_HASHABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashable+=	hs-hashable>=1.2.0
BUILDLINK_PKGSRCDIR.hs-hashable?=	../../wip/hs-hashable

.endif	# HS_HASHABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashable
