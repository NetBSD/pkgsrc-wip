# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/10/02 03:26:52 phonohawk Exp $

BUILDLINK_TREE+=	hs-bytestring-trie

.if !defined(HS_BYTESTRING_TRIE_BUILDLINK3_MK)
HS_BYTESTRING_TRIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bytestring-trie+=	hs-bytestring-trie>=0.1.4
BUILDLINK_PKGSRCDIR.hs-bytestring-trie?=	../../wip/hs-bytestring-trie

.include "../../wip/hs-binary/buildlink3.mk"
.endif	# HS_BYTESTRING_TRIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bytestring-trie
