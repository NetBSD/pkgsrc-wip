# $NetBSD: buildlink3.mk,v 1.2 2010/02/19 06:44:40 phonohawk Exp $

BUILDLINK_TREE+=	hs-binary-strict

.if !defined(HS_BINARY_STRICT_BUILDLINK3_MK)
HS_BINARY_STRICT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-binary-strict+=	hs-binary-strict>=0.4.8
BUILDLINK_PKGSRCDIR.hs-binary-strict?=	../../wip/hs-binary-strict

.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_BINARY_STRICT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-binary-strict
