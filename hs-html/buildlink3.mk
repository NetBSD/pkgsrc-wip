# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:10:24 szptvlfn Exp $

BUILDLINK_TREE+=	hs-html

.if !defined(HS_HTML_BUILDLINK3_MK)
HS_HTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-html+=	hs-html>=1.0.1
BUILDLINK_ABI_DEPENDS.hs-html+=	hs-html>=1.0.1.2nb2
BUILDLINK_PKGSRCDIR.hs-html?=	../../wip/hs-html
.endif	# HS_HTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-html
