# $NetBSD: buildlink3.mk,v 1.7 2012/03/04 07:21:36 phonohawk Exp $

BUILDLINK_TREE+=	hs-dataenc

.if !defined(HS_DATAENC_BUILDLINK3_MK)
HS_DATAENC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dataenc+=	hs-dataenc>=0.14.0
BUILDLINK_PKGSRCDIR.hs-dataenc?=	../../wip/hs-dataenc
.endif	# HS_DATAENC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dataenc
