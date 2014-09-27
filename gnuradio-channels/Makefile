# $NetBSD: Makefile,v 1.2 2014/09/27 23:57:38 makoto Exp $

PKGNAME=	gnuradio-channels-${VERSION}
COMMENT=	Signal processing blocks to simulate channel models of gnuradio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_CHANNELS=ON

.include	"../../mk/bsd.pkg.mk"
