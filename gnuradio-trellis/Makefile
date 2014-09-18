# $NetBSD: Makefile,v 1.1 2014/09/18 00:43:32 makoto Exp $

PKGNAME=	gnuradio-trellis-${VERSION}
COMMENT=	Trellis-based encoding and decoding algorithms for GNU Radio

# (acutually, redundent for now)
PKG_OPTIONS.gnuradio=
.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_TRELLIS=True
CMAKE_ARGS+=	-DENABLE_GR_DIGITAL=True

DEPENDS+=	gnuradio-digital-[0-9]*:../../wip/gnuradio-digital
PLIST_MINUS+=	digital

.include	"../../mk/bsd.pkg.mk"
