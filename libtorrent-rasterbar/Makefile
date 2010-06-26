# $NetBSD: Makefile,v 1.3 2010/06/26 00:30:36 ryo-on Exp $
#

#DISTNAME=	libtorrent-rasterbar-0.15.1_RC
CATEGORIES=	net
MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://www.rasterbar.com/products/libtorrent/index.html
COMMENT=	The rasterbar libtorrent is a feature complete C++ bittorrent library

PKG_DESTDIR_SUPPORT=	user-destdir

#WRKSRC= libtorrent-rasterbar-0.15.1

# These should be removed.
#BUILD_MAKE_FLAGS+=	V=1
CONFIGURE_ARGS+=	--enable-tests
CONFIGURE_ARGS+=	--enable-examples
CONFIGURE_ARGS+=	--enable-debug

PKGCONFIG_OVERRIDE=	libtorrent-rasterbar.pc.in

.include "../../wip/libtorrent-rasterbar/Makefile.common"
