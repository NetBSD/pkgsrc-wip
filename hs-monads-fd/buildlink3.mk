# $NetBSD: buildlink3.mk,v 1.3 2014/05/16 20:47:11 szptvlfn Exp $

BUILDLINK_TREE+=	hs-monads-fd

.if !defined(HS_MONADS_FD_BUILDLINK3_MK)
HS_MONADS_FD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monads-fd+=	hs-monads-fd>=0.2
BUILDLINK_PKGSRCDIR.hs-monads-fd?=	../../wip/hs-monads-fd

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_MONADS_FD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monads-fd
