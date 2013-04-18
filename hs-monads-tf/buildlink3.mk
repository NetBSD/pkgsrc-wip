# $NetBSD: buildlink3.mk,v 1.1 2013/04/18 21:22:38 szptvlfn Exp $

BUILDLINK_TREE+=	hs-monads-tf

.if !defined(HS_MONADS_TF_BUILDLINK3_MK)
HS_MONADS_TF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monads-tf+=	hs-monads-tf>=0.1.0.1
BUILDLINK_PKGSRCDIR.hs-monads-tf?=	../../wip/hs-monads-tf

.endif	# HS_MONADS_TF_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monads-tf
