# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:09 szptvlfn Exp $

BUILDLINK_TREE+=	hs-citeproc-hs

.if !defined(HS_CITEPROC_HS_BUILDLINK3_MK)
HS_CITEPROC_HS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-citeproc-hs+=	hs-citeproc-hs>=0.3.8
BUILDLINK_ABI_DEPENDS.hs-citeproc-hs+=	hs-citeproc-hs>=0.3.8
BUILDLINK_PKGSRCDIR.hs-citeproc-hs?=	../../wip/hs-citeproc-hs

.endif	# HS_CITEPROC_HS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-citeproc-hs
