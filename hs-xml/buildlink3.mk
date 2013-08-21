# $NetBSD: buildlink3.mk,v 1.2 2013/08/21 17:12:22 szptvlfn Exp $

BUILDLINK_TREE+=	hs-xml

.if !defined(HS_XML_BUILDLINK3_MK)
HS_XML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-xml+=	hs-xml>=1.3.13
BUILDLINK_PKGSRCDIR.hs-xml?=	../../wip/hs-xml

.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_XML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-xml
