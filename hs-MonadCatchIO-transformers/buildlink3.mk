# $NetBSD: buildlink3.mk,v 1.5 2014/02/21 10:39:01 szptvlfn Exp $

BUILDLINK_TREE+=	hs-MonadCatchIO-transformers

.if !defined(HS_MONADCATCHIO_TRANSFORMERS_BUILDLINK3_MK)
HS_MONADCATCHIO_TRANSFORMERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-MonadCatchIO-transformers+=	hs-MonadCatchIO-transformers>=0.3.1
BUILDLINK_PKGSRCDIR.hs-MonadCatchIO-transformers?=	../../wip/hs-MonadCatchIO-transformers

.include "../../wip/hs-extensible-exceptions/buildlink3.mk"
.include "../../wip/hs-monads-tf/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_MONADCATCHIO_TRANSFORMERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-MonadCatchIO-transformers
