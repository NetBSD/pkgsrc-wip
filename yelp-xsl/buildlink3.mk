# $NetBSD: buildlink3.mk,v 1.2 2011/08/05 14:13:57 obache Exp $

BUILDLINK_TREE+=	yelp-xsl

.if !defined(YELP_XSL_BUILDLINK3_MK)
YELP_XSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yelp-xsl+=	yelp-xsl>=2.31.1
BUILDLINK_PKGSRCDIR.yelp-xsl?=	../../wip/yelp-xsl

.endif	# YELP_XSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-yelp-xsl
