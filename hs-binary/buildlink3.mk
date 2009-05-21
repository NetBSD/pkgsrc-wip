# $NetBSD: buildlink3.mk,v 1.4 2009/05/21 04:50:37 phonohawk Exp $

BUILDLINK_TREE+=	hs-binary

.if !defined(HS_BINARY_BUILDLINK3_MK)
HS_BINARY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-binary+=	hs-binary>=0.5.0.1
BUILDLINK_PKGSRCDIR.hs-binary?=	../../wip/hs-binary
.endif # HS_BINARY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-binary
