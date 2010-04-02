# $NetBSD: buildlink3.mk,v 1.2 2010/04/02 12:40:27 ryo-on Exp $

BUILDLINK_TREE+=	libtorrent-rasterbar

.if !defined(LIBTORRENT_RASTERBAR_BUILDLINK3_MK)
LIBTORRENT_RASTERBAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtorrent-rasterbar+=	libtorrent-rasterbar>=0.15.0
BUILDLINK_PKGSRCDIR.libtorrent-rasterbar?=	../../wip/libtorrent-rasterbar

.endif	# LIBTORRENT_RASTERBAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtorrent-rasterbar
