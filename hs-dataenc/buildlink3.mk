# $NetBSD: buildlink3.mk,v 1.4 2009/06/04 05:09:16 phonohawk Exp $

BUILDLINK_TREE+=	hs-dataenc

.if !defined(HS_DATAENC_BUILDLINK3_MK)
HS_DATAENC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dataenc+=	hs-dataenc>=0.13.0.0
BUILDLINK_PKGSRCDIR.hs-dataenc?=	../../wip/hs-dataenc
.endif	# HS_DATAENC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dataenc
