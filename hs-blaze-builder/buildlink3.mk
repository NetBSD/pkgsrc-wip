# $NetBSD: buildlink3.mk,v 1.3 2012/02/02 13:38:05 phonohawk Exp $

BUILDLINK_TREE+=	hs-blaze-builder

.if !defined(HS_BLAZE_BUILDER_BUILDLINK3_MK)
HS_BLAZE_BUILDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blaze-builder+=	hs-blaze-builder>=0.3.1
BUILDLINK_PKGSRCDIR.hs-blaze-builder?=	../../wip/hs-blaze-builder

.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_BLAZE_BUILDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blaze-builder
