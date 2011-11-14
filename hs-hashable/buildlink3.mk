# $NetBSD: buildlink3.mk,v 1.2 2011/11/14 09:30:24 phonohawk Exp $

BUILDLINK_TREE+=	hs-hashable

.if !defined(HS_HASHABLE_BUILDLINK3_MK)
HS_HASHABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashable+=	hs-hashable>=1.1.2
BUILDLINK_PKGSRCDIR.hs-hashable?=	../../wip/hs-hashable

.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_HASHABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashable
