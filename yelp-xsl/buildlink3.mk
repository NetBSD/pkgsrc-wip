# $NetBSD: buildlink3.mk,v 1.1 2011/07/31 21:47:45 jihbed Exp $

BUILDLINK_TREE+=	yelp-xsl

.if !defined(YELP_XSL_BUILDLINK3_MK)
YELP_XSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yelp-xsl+=	yelp-xsl>=2.31.1
BUILDLINK_PKGSRCDIR.yelp-xsl?=	../../wip/yelp-xsl

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.endif	# YELP_XSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-yelp-xsl
