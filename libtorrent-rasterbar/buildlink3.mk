# $NetBSD: buildlink3.mk,v 1.3 2010/06/26 00:30:36 ryo-on Exp $

BUILDLINK_TREE+=	libtorrent-rasterbar

.if !defined(LIBTORRENT_RASTERBAR_BUILDLINK3_MK)
LIBTORRENT_RASTERBAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtorrent-rasterbar+=	libtorrent-rasterbar>=0.14.10
BUILDLINK_PKGSRCDIR.libtorrent-rasterbar?=	../../wip/libtorrent-rasterbar

.endif	# LIBTORRENT_RASTERBAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtorrent-rasterbar
