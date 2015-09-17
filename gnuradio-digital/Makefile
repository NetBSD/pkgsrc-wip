# $NetBSD: Makefile,v 1.2 2015/09/17 13:48:05 makoto Exp $

PKGNAME=	gnuradio-digital-${VERSION}
COMMENT=	Digital related algorithms for GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"
# link to libgnuradio-fft.so.${PKGVERSON_NOREV}
.include       "../../wip/gnuradio-core/buildlink3.mk"


CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_DIGITAL=True

.include	"../../mk/bsd.pkg.mk"
