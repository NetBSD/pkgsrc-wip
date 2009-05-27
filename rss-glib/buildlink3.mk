# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/05/27 15:13:54 jihbed Exp $

BUILDLINK_TREE+=	rss-glib

.if !defined(RSS_GLIB_BUILDLINK3_MK)
RSS_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rss-glib+=	rss-glib>=0.2.2
BUILDLINK_PKGSRCDIR.rss-glib?=	../../wip/rss-glib


.include "../../devel/glib2/buildlink3.mk"
.include "../../wip/libmrss/buildlink3.mk"
.endif	# RSS_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-rss-glib
