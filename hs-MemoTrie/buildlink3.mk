# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:01 szptvlfn Exp $

BUILDLINK_TREE+=	hs-MemoTrie

.if !defined(HS_MEMOTRIE_BUILDLINK3_MK)
HS_MEMOTRIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-MemoTrie+=	hs-MemoTrie>=0.6.1
BUILDLINK_ABI_DEPENDS.hs-MemoTrie+=	hs-MemoTrie>=0.6.1
BUILDLINK_PKGSRCDIR.hs-MemoTrie?=	../../wip/hs-MemoTrie

.endif	# HS_MEMOTRIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-MemoTrie
