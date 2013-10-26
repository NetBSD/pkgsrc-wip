# $NetBSD: buildlink3.mk,v 1.8 2013/10/26 22:40:14 szptvlfn Exp $

BUILDLINK_TREE+=	hs-dataenc

.if !defined(HS_DATAENC_BUILDLINK3_MK)
HS_DATAENC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dataenc+=	hs-dataenc>=0.14.0.5
BUILDLINK_PKGSRCDIR.hs-dataenc?=	../../wip/hs-dataenc
.endif	# HS_DATAENC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dataenc
