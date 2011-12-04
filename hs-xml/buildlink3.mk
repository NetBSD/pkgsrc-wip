# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/12/04 13:04:14 phonohawk Exp $

BUILDLINK_TREE+=	hs-xml

.if !defined(HS_XML_BUILDLINK3_MK)
HS_XML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-xml+=	hs-xml>=1.3.10
BUILDLINK_PKGSRCDIR.hs-xml?=	../../wip/hs-xml

.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_XML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-xml
