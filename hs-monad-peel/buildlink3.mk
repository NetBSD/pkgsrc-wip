# $NetBSD: buildlink3.mk,v 1.6 2014/08/29 14:10:26 szptvlfn Exp $

BUILDLINK_TREE+=	hs-monad-peel

.if !defined(HS_MONAD_PEEL_BUILDLINK3_MK)
HS_MONAD_PEEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monad-peel+=	hs-monad-peel>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-monad-peel+=	hs-monad-peel>=0.1.1
BUILDLINK_PKGSRCDIR.hs-monad-peel?=	../../wip/hs-monad-peel

.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_MONAD_PEEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monad-peel
