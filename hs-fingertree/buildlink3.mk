# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/11 10:20:05 phonohawk Exp $

BUILDLINK_TREE+=	hs-fingertree

.if !defined(HS_FINGERTREE_BUILDLINK3_MK)
HS_FINGERTREE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fingertree+=	hs-fingertree>=0.0
BUILDLINK_PKGSRCDIR.hs-fingertree?=	../../wip/hs-fingertree
.endif	# HS_FINGERTREE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fingertree
