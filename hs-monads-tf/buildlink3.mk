# $NetBSD: buildlink3.mk,v 1.2 2014/04/24 12:33:49 szptvlfn Exp $

BUILDLINK_TREE+=	hs-monads-tf

.if !defined(HS_MONADS_TF_BUILDLINK3_MK)
HS_MONADS_TF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monads-tf+=	hs-monads-tf>=0.1.0
BUILDLINK_PKGSRCDIR.hs-monads-tf?=	../../wip/hs-monads-tf

.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_MONADS_TF_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monads-tf
