# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:28 szptvlfn Exp $

BUILDLINK_TREE+=	hs-stream-fusion

.if !defined(HS_STREAM_FUSION_BUILDLINK3_MK)
HS_STREAM_FUSION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-stream-fusion+=	hs-stream-fusion>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-stream-fusion+=	hs-stream-fusion>=0.1.2.2
BUILDLINK_PKGSRCDIR.hs-stream-fusion?=		../../wip/hs-stream-fusion
.endif	# HS_STREAM_FUSION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-stream-fusion
