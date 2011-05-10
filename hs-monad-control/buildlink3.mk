# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/05/10 12:56:48 phonohawk Exp $

BUILDLINK_TREE+=	hs-monad-control

.if !defined(HS_MONAD_CONTROL_BUILDLINK3_MK)
HS_MONAD_CONTROL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monad-control+=	hs-monad-control>=0.2
BUILDLINK_PKGSRCDIR.hs-monad-control?=	../../wip/hs-monad-control

.include "../../wip/hs-base-unicode-symbols/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_MONAD_CONTROL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monad-control
