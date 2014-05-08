# $NetBSD: buildlink3.mk,v 1.5 2014/05/08 00:32:53 szptvlfn Exp $

BUILDLINK_TREE+=	hs-contravariant

.if !defined(HS_CONTRAVARIANT_BUILDLINK3_MK)
HS_CONTRAVARIANT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-contravariant+=	hs-contravariant>=0.5.2
BUILDLINK_PKGSRCDIR.hs-contravariant?=	../../wip/hs-contravariant

.include "../../wip/hs-tagged/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.include "../../wip/hs-transformers-compat/buildlink3.mk"
.endif	# HS_CONTRAVARIANT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-contravariant
