# $NetBSD: buildlink3.mk,v 1.8 2014/08/29 14:10:10 szptvlfn Exp $

BUILDLINK_TREE+=	hs-contravariant

.if !defined(HS_CONTRAVARIANT_BUILDLINK3_MK)
HS_CONTRAVARIANT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-contravariant+=	hs-contravariant>=0.5.2
BUILDLINK_ABI_DEPENDS.hs-contravariant+=	hs-contravariant>=0.5.2
BUILDLINK_PKGSRCDIR.hs-contravariant?=		../../wip/hs-contravariant

.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_CONTRAVARIANT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-contravariant
