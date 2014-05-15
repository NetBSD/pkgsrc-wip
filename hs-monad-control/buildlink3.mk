# $NetBSD: buildlink3.mk,v 1.4 2014/05/15 21:49:09 szptvlfn Exp $

BUILDLINK_TREE+=	hs-monad-control

.if !defined(HS_MONAD_CONTROL_BUILDLINK3_MK)
HS_MONAD_CONTROL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monad-control+=	hs-monad-control>=0.3.2
BUILDLINK_PKGSRCDIR.hs-monad-control?=	../../wip/hs-monad-control

.include "../../wip/hs-base-unicode-symbols/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.endif	# HS_MONAD_CONTROL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monad-control
