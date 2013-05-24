# $NetBSD: buildlink3.mk,v 1.1 2013/05/24 21:46:56 szptvlfn Exp $

BUILDLINK_TREE+=	hs-MemoTrie

.if !defined(HS_MEMOTRIE_BUILDLINK3_MK)
HS_MEMOTRIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-MemoTrie+=	hs-MemoTrie>=0.6.1
BUILDLINK_PKGSRCDIR.hs-MemoTrie?=	../../wip/hs-MemoTrie

.endif	# HS_MEMOTRIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-MemoTrie
