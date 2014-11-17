# $NetBSD: Makefile,v 1.2 2014/11/17 13:51:06 makoto Exp $

PKGNAME=	gnuradio-trellis-${VERSION}
COMMENT=	Trellis-based encoding and decoding algorithms for GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_TRELLIS=True
CMAKE_ARGS+=	-DENABLE_GR_DIGITAL=True

DEPENDS+=	gnuradio-digital-[0-9]*:../../wip/gnuradio-digital
PLIST_MINUS+=	digital

.include	"../../mk/bsd.pkg.mk"
