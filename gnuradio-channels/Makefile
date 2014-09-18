# $NetBSD: Makefile,v 1.1 2014/09/18 00:43:30 makoto Exp $

PKGNAME=	gnuradio-channels-${VERSION}
COMMENT=        Signal processing blocks to simulate channel models of gnuradio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_CHANNELS=ON

.include	"../../mk/bsd.pkg.mk"
