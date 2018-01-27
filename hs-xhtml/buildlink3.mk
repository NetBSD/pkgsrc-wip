# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:30 szptvlfn Exp $

BUILDLINK_TREE+=	hs-xhtml

.if !defined(HS_XHTML_BUILDLINK3_MK)
HS_XHTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-xhtml+=	hs-xhtml>=3000.2.1
BUILDLINK_ABI_DEPENDS.hs-xhtml+=	hs-xhtml>=3000.2.1
BUILDLINK_PKGSRCDIR.hs-xhtml?=		../../wip/hs-xhtml
.endif	# HS_XHTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-xhtml
