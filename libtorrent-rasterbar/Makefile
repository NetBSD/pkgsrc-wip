# $NetBSD: Makefile,v 1.2 2010/04/02 12:40:27 ryo-on Exp $
#

DISTNAME=	libtorrent-rasterbar-0.15.0
CATEGORIES=	net
MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://www.rasterbar.com/products/libtorrent/index.html
COMMENT=	The rasterbar libtorrent is a feature complete C++ bittorrent library

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_MAKE_FLAGS+=	V=1

PKGCONFIG_OVERRIDE=	libtorrent-rasterbar.pc.in

.include "../../wip/libtorrent-rasterbar/Makefile.common"
