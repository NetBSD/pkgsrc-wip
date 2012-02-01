# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/02/01 16:11:36 phonohawk Exp $

BUILDLINK_TREE+=	hs-contravariant

.if !defined(HS_CONTRAVARIANT_BUILDLINK3_MK)
HS_CONTRAVARIANT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-contravariant+=	hs-contravariant>=0.1.3
BUILDLINK_PKGSRCDIR.hs-contravariant?=	../../wip/hs-contravariant

.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_CONTRAVARIANT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-contravariant
