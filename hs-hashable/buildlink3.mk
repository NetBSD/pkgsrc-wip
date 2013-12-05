# $NetBSD: buildlink3.mk,v 1.5 2013/12/05 08:26:42 phonohawk Exp $

BUILDLINK_TREE+=	hs-hashable

.if !defined(HS_HASHABLE_BUILDLINK3_MK)
HS_HASHABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashable+=	hs-hashable>=1.2.1
BUILDLINK_PKGSRCDIR.hs-hashable?=	../../wip/hs-hashable

.endif	# HS_HASHABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashable
