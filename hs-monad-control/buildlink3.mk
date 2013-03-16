# $NetBSD: buildlink3.mk,v 1.3 2013/03/16 05:58:36 szptvlfn Exp $

BUILDLINK_TREE+=	hs-monad-control

.if !defined(HS_MONAD_CONTROL_BUILDLINK3_MK)
HS_MONAD_CONTROL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monad-control+=	hs-monad-control>=0.3.2
BUILDLINK_PKGSRCDIR.hs-monad-control?=	../../wip/hs-monad-control

.include "../../wip/hs-base-unicode-symbols/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.include "../../wip/hs-transformers-base/buildlink3.mk"
.endif	# HS_MONAD_CONTROL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monad-control
