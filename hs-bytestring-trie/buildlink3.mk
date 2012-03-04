# $NetBSD: buildlink3.mk,v 1.2 2012/03/04 05:54:43 phonohawk Exp $

BUILDLINK_TREE+=	hs-bytestring-trie

.if !defined(HS_BYTESTRING_TRIE_BUILDLINK3_MK)
HS_BYTESTRING_TRIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bytestring-trie+=	hs-bytestring-trie>=0.2.3
BUILDLINK_PKGSRCDIR.hs-bytestring-trie?=	../../wip/hs-bytestring-trie

.endif	# HS_BYTESTRING_TRIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bytestring-trie
