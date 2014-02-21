# $NetBSD: buildlink3.mk,v 1.2 2014/02/21 10:39:01 szptvlfn Exp $

BUILDLINK_TREE+=	hs-monad-peel

.if !defined(HS_MONAD_PEEL_BUILDLINK3_MK)
HS_MONAD_PEEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monad-peel+=	hs-monad-peel>=0.1
BUILDLINK_PKGSRCDIR.hs-monad-peel?=	../../wip/hs-monad-peel

.include "../../wip/hs-extensible-exceptions/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_MONAD_PEEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monad-peel
