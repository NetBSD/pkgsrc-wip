# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/04/01 13:41:35 ryo-on Exp $

BUILDLINK_TREE+=	libtorrent-rasterbar

.if !defined(LIBTORRENT_RASTERBAR_BUILDLINK3_MK)
LIBTORRENT_RASTERBAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtorrent-rasterbar+=	libtorrent-rasterbar>=0.15.0
BUILDLINK_PKGSRCDIR.libtorrent-rasterbar?=	../../local/libtorrent-rasterbar

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBTORRENT_RASTERBAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtorrent-rasterbar
