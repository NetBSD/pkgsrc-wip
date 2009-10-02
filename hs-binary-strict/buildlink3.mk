# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/10/02 03:23:36 phonohawk Exp $

BUILDLINK_TREE+=	hs-binary-strict

.if !defined(HS_BINARY_STRICT_BUILDLINK3_MK)
HS_BINARY_STRICT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-binary-strict+=	hs-binary-strict>=0.4.5
BUILDLINK_PKGSRCDIR.hs-binary-strict?=	../../wip/hs-binary-strict
.endif	# HS_BINARY_STRICT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-binary-strict
