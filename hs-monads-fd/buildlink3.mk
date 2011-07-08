# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/08 08:33:34 phonohawk Exp $

BUILDLINK_TREE+=	hs-monads-fd

.if !defined(HS_MONADS_FD_BUILDLINK3_MK)
HS_MONADS_FD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monads-fd+=	hs-monads-fd>=0.2
BUILDLINK_PKGSRCDIR.hs-monads-fd?=	../../wip/hs-monads-fd

.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_MONADS_FD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monads-fd
