# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/29 16:09:52 phonohawk Exp $

BUILDLINK_TREE+=	hs-blaze-builder

.if !defined(HS_BLAZE_BUILDER_BUILDLINK3_MK)
HS_BLAZE_BUILDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blaze-builder+=	hs-blaze-builder>=0.3
BUILDLINK_PKGSRCDIR.hs-blaze-builder?=	../../wip/hs-blaze-builder

.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_BLAZE_BUILDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blaze-builder
