# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/02/01 16:18:18 phonohawk Exp $

BUILDLINK_TREE+=	hs-distributive

.if !defined(HS_DISTRIBUTIVE_BUILDLINK3_MK)
HS_DISTRIBUTIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-distributive+=	hs-distributive>=0.2.0
BUILDLINK_PKGSRCDIR.hs-distributive?=	../../wip/hs-distributive

.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_DISTRIBUTIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-distributive
