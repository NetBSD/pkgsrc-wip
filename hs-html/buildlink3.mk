# $NetBSD: buildlink3.mk,v 1.3 2009/09/24 06:41:03 phonohawk Exp $

BUILDLINK_TREE+=	hs-html

.if !defined(HS_HTML_BUILDLINK3_MK)
HS_HTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-html+=	hs-html>=1.0.1.2nb2
BUILDLINK_PKGSRCDIR.hs-html?=	../../wip/hs-html
.endif	# HS_HTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-html
