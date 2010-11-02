# $NetBSD: buildlink3.mk,v 1.2 2010/11/02 16:50:07 phonohawk Exp $

BUILDLINK_TREE+=	hs-MonadCatchIO-transformers

.if !defined(HS_MONADCATCHIO_TRANSFORMERS_BUILDLINK3_MK)
HS_MONADCATCHIO_TRANSFORMERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-MonadCatchIO-transformers+=	hs-MonadCatchIO-transformers>=0.2.2.0
BUILDLINK_PKGSRCDIR.hs-MonadCatchIO-transformers?=	../../wip/hs-MonadCatchIO-transformers

.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_MONADCATCHIO_TRANSFORMERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-MonadCatchIO-transformers
