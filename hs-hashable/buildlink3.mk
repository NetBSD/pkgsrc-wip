# $NetBSD: buildlink3.mk,v 1.3 2013/02/20 11:42:32 szptvlfn Exp $

BUILDLINK_TREE+=	hs-hashable

.if !defined(HS_HASHABLE_BUILDLINK3_MK)
HS_HASHABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashable+=	hs-hashable>=1.1.2
BUILDLINK_PKGSRCDIR.hs-hashable?=	../../wip/hs-hashable

.endif	# HS_HASHABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashable
