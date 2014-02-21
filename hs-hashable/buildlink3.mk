# $NetBSD: buildlink3.mk,v 1.6 2014/02/21 10:39:01 szptvlfn Exp $

BUILDLINK_TREE+=	hs-hashable

.if !defined(HS_HASHABLE_BUILDLINK3_MK)
HS_HASHABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashable+=	hs-hashable>=1.2.1
BUILDLINK_PKGSRCDIR.hs-hashable?=	../../wip/hs-hashable

.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_HASHABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashable
