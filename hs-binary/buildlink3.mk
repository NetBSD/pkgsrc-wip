# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:42 jsonn Exp $

BUILDLINK_TREE+=	hs-binary

.if !defined(HS_BINARY_BUILDLINK3_MK)
HS_BINARY_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hs-binary?=	build
BUILDLINK_API_DEPENDS.hs-binary+=	hs-binary>=0.4.4nb1
BUILDLINK_PKGSRCDIR.hs-binary?=	../../wip/hs-binary
.endif # HS_BINARY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-binary
