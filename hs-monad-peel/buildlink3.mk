# $NetBSD: buildlink3.mk,v 1.3 2014/03/07 12:42:22 szptvlfn Exp $

BUILDLINK_TREE+=	hs-monad-peel

.if !defined(HS_MONAD_PEEL_BUILDLINK3_MK)
HS_MONAD_PEEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monad-peel+=	hs-monad-peel>=0.1.1
BUILDLINK_PKGSRCDIR.hs-monad-peel?=	../../wip/hs-monad-peel

.include "../../wip/hs-extensible-exceptions/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_MONAD_PEEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monad-peel
