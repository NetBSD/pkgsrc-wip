# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/04/23 06:34:21 phonohawk Exp $

BUILDLINK_TREE+=	hs-tfp

.if !defined(HS_TFP_BUILDLINK3_MK)
HS_TFP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tfp+=	hs-tfp>=0.2
BUILDLINK_PKGSRCDIR.hs-tfp?=	../../wip/hs-tfp
.endif	# HS_TFP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tfp
