# $NetBSD: Makefile,v 1.3 2015/09/17 13:48:06 makoto Exp $

PKGNAME=	gnuradio-noaa-${VERSION}
COMMENT=	NOAA, Weather Satellite Reception module of GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_NOAA=ON

.include	"../../mk/bsd.pkg.mk"
