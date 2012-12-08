# $NetBSD: buildlink3.mk,v 1.3 2012/12/08 16:56:41 ryo-on Exp $

BUILDLINK_TREE+=	rss-glib

.if !defined(RSS_GLIB_BUILDLINK3_MK)
RSS_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rss-glib+=	rss-glib>=0.2.2
BUILDLINK_ABI_DEPENDS.rss-glib?=	rss-glib>=0.2.2nb1
BUILDLINK_PKGSRCDIR.rss-glib?=	../../wip/rss-glib


.include "../../devel/glib2/buildlink3.mk"
.include "../../www/libmrss/buildlink3.mk"
.endif	# RSS_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-rss-glib
