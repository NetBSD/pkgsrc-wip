# $NetBSD: buildlink3.mk,v 1.2 2014/05/25 21:59:29 szptvlfn Exp $

BUILDLINK_TREE+=	hs-mwc-random

.if !defined(HS_MWC_RANDOM_BUILDLINK3_MK)
HS_MWC_RANDOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mwc-random+=	hs-mwc-random>=0.13.1
BUILDLINK_PKGSRCDIR.hs-mwc-random?=	../../wip/hs-mwc-random

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../wip/hs-vector/buildlink3.mk"
.endif	# HS_MWC_RANDOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mwc-random
