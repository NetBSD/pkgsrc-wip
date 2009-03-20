# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:42 jsonn Exp $

BUILDLINK_TREE+=	hs-SHA

.if !defined(HS_SHA_BUILDLINK3_MK)
HS_SHA_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hs-SHA?=	build
BUILDLINK_API_DEPENDS.hs-SHA+=	hs-SHA>=1.0.3
BUILDLINK_PKGSRCDIR.hs-SHA?=	../../wip/hs-SHA

.include "../../wip/QuickCheck/buildlink3.mk"
.endif # HS_SHA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-SHA
