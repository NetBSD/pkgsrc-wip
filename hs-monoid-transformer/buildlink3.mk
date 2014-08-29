# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:27 szptvlfn Exp $

BUILDLINK_TREE+=	hs-monoid-transformer

.if !defined(HS_MONOID_TRANSFORMER_BUILDLINK3_MK)
HS_MONOID_TRANSFORMER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monoid-transformer+=	hs-monoid-transformer>=0.0.2
BUILDLINK_ABI_DEPENDS.hs-monoid-transformer+=	hs-monoid-transformer>=0.0.2
BUILDLINK_PKGSRCDIR.hs-monoid-transformer?=	../../wip/hs-monoid-transformer
.endif	# HS_MONOID_TRANSFORMER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monoid-transformer
