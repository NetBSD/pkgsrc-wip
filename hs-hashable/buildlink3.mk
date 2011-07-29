# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/29 16:19:15 phonohawk Exp $

BUILDLINK_TREE+=	hs-hashable

.if !defined(HS_HASHABLE_BUILDLINK3_MK)
HS_HASHABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashable+=	hs-hashable>=1.1
BUILDLINK_PKGSRCDIR.hs-hashable?=	../../wip/hs-hashable

.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_HASHABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashable
