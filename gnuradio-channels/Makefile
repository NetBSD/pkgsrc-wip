# $NetBSD: Makefile,v 1.16 2019/08/22 12:23:21 ryoon Exp $

PKGNAME=	gnuradio-channels-${VERSION}
COMMENT=	Signal processing blocks to simulate channel models of GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_CHANNELS=ON
CMAKE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include	"../../mk/bsd.pkg.mk"
