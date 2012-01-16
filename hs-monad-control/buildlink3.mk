# $NetBSD: buildlink3.mk,v 1.2 2012/01/16 05:16:09 phonohawk Exp $

BUILDLINK_TREE+=	hs-monad-control

.if !defined(HS_MONAD_CONTROL_BUILDLINK3_MK)
HS_MONAD_CONTROL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monad-control+=	hs-monad-control>=0.3.1
BUILDLINK_PKGSRCDIR.hs-monad-control?=	../../wip/hs-monad-control

.include "../../wip/hs-base-unicode-symbols/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.include "../../wip/hs-transformers-base/buildlink3.mk"
.endif	# HS_MONAD_CONTROL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monad-control
