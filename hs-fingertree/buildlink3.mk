# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:12 szptvlfn Exp $

BUILDLINK_TREE+=	hs-fingertree

.if !defined(HS_FINGERTREE_BUILDLINK3_MK)
HS_FINGERTREE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fingertree+=	hs-fingertree>=0.0.1
BUILDLINK_ABI_DEPENDS.hs-fingertree+=	hs-fingertree>=0.0.1.0
BUILDLINK_PKGSRCDIR.hs-fingertree?=	../../wip/hs-fingertree
.endif	# HS_FINGERTREE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fingertree
