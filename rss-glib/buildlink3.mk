# $NetBSD: buildlink3.mk,v 1.2 2010/01/17 12:03:32 thomasklausner Exp $

BUILDLINK_TREE+=	rss-glib

.if !defined(RSS_GLIB_BUILDLINK3_MK)
RSS_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rss-glib+=	rss-glib>=0.2.2
BUILDLINK_ABI_DEPENDS.rss-glib?=	rss-glib>=0.2.2nb1
BUILDLINK_PKGSRCDIR.rss-glib?=	../../wip/rss-glib


.include "../../devel/glib2/buildlink3.mk"
.include "../../wip/libmrss/buildlink3.mk"
.endif	# RSS_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-rss-glib
