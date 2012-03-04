# $NetBSD: buildlink3.mk,v 1.9 2012/03/04 07:42:04 phonohawk Exp $

BUILDLINK_TREE+=	hs-utf8-string

.if !defined(HS_UTF8_STRING_BUILDLINK3_MK)
HS_UTF8_STRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-utf8-string+=	hs-utf8-string>=0.3.7
BUILDLINK_PKGSRCDIR.hs-utf8-string?=	../../wip/hs-utf8-string

.endif # HS_UTF8_STRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-utf8-string
