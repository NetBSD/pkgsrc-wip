# $NetBSD: buildlink3.mk,v 1.5 2009/09/23 07:04:49 phonohawk Exp $

BUILDLINK_TREE+=	hs-binary

.if !defined(HS_BINARY_BUILDLINK3_MK)
HS_BINARY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-binary+=	hs-binary>=0.5.0.2
BUILDLINK_PKGSRCDIR.hs-binary?=	../../wip/hs-binary
.endif # HS_BINARY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-binary
