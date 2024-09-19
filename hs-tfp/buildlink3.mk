# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:29 szptvlfn Exp $

BUILDLINK_TREE+=	hs-tfp

.if !defined(HS_TFP_BUILDLINK3_MK)
HS_TFP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tfp+=	hs-tfp>=0.2
BUILDLINK_ABI_DEPENDS.hs-tfp+=	hs-tfp>=0.2
BUILDLINK_PKGSRCDIR.hs-tfp?=	../../wip/hs-tfp
.endif	# HS_TFP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tfp
