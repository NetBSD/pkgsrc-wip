# $NetBSD: Makefile,v 1.17 2019/08/22 12:23:22 ryoon Exp $

PKGNAME=	gnuradio-digital-${VERSION}
COMMENT=	Digital related algorithms for GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"
# link to libgnuradio-fft.so.${PKGVERSON_NOREV}
.include       "../../wip/gnuradio-core/buildlink3.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_DIGITAL=True
CMAKE_ARGS+=    -DENABLE_GRC=True

PLIST_MINUS+=	companion

.include	"../../mk/bsd.pkg.mk"
