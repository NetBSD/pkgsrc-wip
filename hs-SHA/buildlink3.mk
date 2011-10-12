# $NetBSD: buildlink3.mk,v 1.4 2011/10/12 19:02:55 phonohawk Exp $

BUILDLINK_TREE+=	hs-SHA

.if !defined(HS_SHA_BUILDLINK3_MK)
HS_SHA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-SHA+=	hs-SHA>=1.5.0
BUILDLINK_PKGSRCDIR.hs-SHA?=	../../wip/hs-SHA

.include "../../wip/hs-binary/buildlink3.mk"
.endif	# HS_SHA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-SHA
