# $NetBSD: buildlink3.mk,v 1.2 2010/11/02 16:28:59 phonohawk Exp $

BUILDLINK_TREE+=	hs-base-unicode-symbols

.if !defined(HS_BASE_UNICODE_SYMBOLS_BUILDLINK3_MK)
HS_BASE_UNICODE_SYMBOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-base-unicode-symbols+=	hs-base-unicode-symbols>=0.2.1.1
BUILDLINK_PKGSRCDIR.hs-base-unicode-symbols?=	../../wip/hs-base-unicode-symbols
.endif	# HS_BASE_UNICODE_SYMBOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-base-unicode-symbols
