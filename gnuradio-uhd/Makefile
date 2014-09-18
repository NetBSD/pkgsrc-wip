# $NetBSD: Makefile,v 1.1 2014/09/18 00:43:32 makoto Exp $

PKGNAME=	gnuradio-uhd-${VERSION}
COMMENT=	Uhd-based encoding and decoding algorithms for GNU Radio

# (acutually, redundent for now)
PKG_OPTIONS.gnuradio=
.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=    -DENABLE_DEFAULT=False
CMAKE_ARGS+=    -DENABLE_GR_UHD=True
CMAKE_ARGS+=    -DENABLE_PYTHON=True

.include	"../../ham/uhd/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
